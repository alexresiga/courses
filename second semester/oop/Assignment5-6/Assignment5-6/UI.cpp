//
//  UI.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "UI.hpp"
#include "ValidatorException.hpp"
#include <string>
#include <vector>

using namespace std;

void UI::printMenu()
{
    cout<<endl;
    cout << "1 - Administrator"<<endl;
    cout << "2 - User" << endl;
    cout << "0 - Exit." << endl;
    cout<<endl;
}


void UI::printAdminMenu()
{
    cout<<endl;
    cout << "Possible commands: " << endl;
    cout << "\t 1 - Add movie." << endl;
    cout << "\t 2 - Remove movie." << endl;
    cout << "\t 3 - Update movie." << endl;
    cout << "\t 4 - Display all." << endl;
    cout << "\t 0 - Back." << endl;
    cout<<endl;
}

void UI::printUserMenu()
{
    cout<<endl;
    cout << "Possible commands: " << endl;
    cout << "\t 1 - See movies by genre." << endl;
    cout << "\t 2 - Remove movie from watchlist.\n";
    cout << "\t 3 - Play movies in watchlist.\n";
    cout << "\t 4 - Next movie..\n";
    cout << "\t 0 - Back." << endl;
    cout<<endl;
    
}

void UI::addMovieUI()
{
    cout << "Enter the title: ";
    string title;
    getline(cin, title);
    cout << "Enter the genre: ";
    string genre;
    getline(cin, genre);
    unsigned int year = 0, likes = 0;
    cout << "Enter year of release: ";
    cin >> year;
    cin.ignore();
    cout << "Enter number of likes: ";
    cin >> likes;
    cin.ignore();
    cout << "Enter trailer link: ";
    string trailer;
    getline(cin, trailer);
    
    this->ctrl.addMovieToRepo(title, genre, year, likes, trailer);
}

void UI::removeMovieUI()
{
    cout<<"enter title: ";
    string title;
    getline(cin, title);
    cout<<"Enter year of release: ";
    unsigned int year = 0;
    cin>>year;
    cin.ignore();
    
    this->ctrl.removeMovieFromRepo(title, year);
    
}

void UI::updateMovieUI()
{
    cout<<"enter title: ";
    string title;
    getline(cin, title);
    cout<<"Enter year of release: ";
    unsigned int year = 0;
    cin>>year;
    cin.ignore();
    
    string new_genre;
    cout<<"Enter new genre: ";
    getline(cin, new_genre);
    int new_likes;
    cout << "Enter number of likes: ";
    cin >> new_likes;
    cin.ignore();
    cout << "Enter trailer link: ";
    string new_trailer;
    getline(cin, new_trailer);
    
    this->ctrl.updateMovieRepo(title, new_genre, year, new_likes, new_trailer);
    
}

void UI::displayAllMoviesRepo()
{
    vector<Movie> v = this->ctrl.getRepo().getMovies();
    
    if (v.size() == 0)
    {
        cout<<"There are no movies in the repository.\n";
        return;
    }
    
    for (auto m: v)
    {
        cout << m.getTitle() << " - " << m.getGenre() << ", " << m.getYear() << ": " << m.getLikes() <<" likes - "<<m.getTrailer()<<".\n\n";
    }
}

void UI::addMoviesByGenreUI()
{
    cout<<"Enter desired genre: ";
    string genre;
    getline(cin, genre);
    vector<Movie> movies = this->ctrl.getRepo().getMovies();
    
    vector<Movie> selected;
    copy_if(movies.begin(), movies.end(), back_inserter(selected), [genre](const Movie& m){return m.getGenre() == genre;});
    
    int j = 0, c = 1;
    while (j < selected.size())
    {
        Movie m = selected[j];
        cout << m.getTitle() << " - " << m.getGenre() << ", " << m.getYear() << ": " << m.getLikes() << " likes.\n";
        m.play();
        string answer;
        cout << "Do you want to add this movie to your watchlist?\n";
        getline(cin, answer);
        if (answer == "yes")
            this->ctrl.getWatchlist().addToWatchlist(m);
        (j == selected.size() - 1) ? j = 0 : j++;
        c++;
        if (c%selected.size() == 1)
        {
            string ceva;
            cout << "\nExit?\n";
            getline(cin, ceva);
            if (ceva == "yes") break;
        }
    }
}

void UI::deleteMovieWatchlistUI()
{
    cout<<"enter title: ";
    string title;
    getline(cin, title);
    cout<<"Enter year of release: ";
    unsigned int year = 0;
    cin>>year;
    cin.ignore();
    
    for (int i = 0; i < this->ctrl.watchlist.movies.size(); ++i)
    {
        Movie ceva = this->ctrl.watchlist.movies[i];
        if (ceva.getTitle() == title and ceva.getYear() == year)
        {
            string ans;
            cout << "Did you like this movie?";
            getline(cin, ans);
            if (ans == "yes")
                ceva.increaseLikes();
            this->ctrl.watchlist.movies.erase(ctrl.watchlist.movies.begin() +i);
            this->ctrl.updateMovieRepo(ceva.getTitle(), ceva.getGenre(), ceva.getYear(), ceva.getLikes(), ceva.getTrailer());
            
        }
    }
}

void UI::run()
{
    
    while (true)
    {
        UI::printMenu();
        int command{0};
        cout<<"Input the command: ";
        cin>>command;
        cin.ignore();
        if (!command)
            break;
        
        if (command == 1)
        {
            while (true)
            {
                try
                {
                UI::printAdminMenu();
                int commandAdmin{0};
                cout<< "Input the command: ";
                cin>> commandAdmin;
                cout<<endl;
                cin.ignore();
                if (!commandAdmin)
                    break;
                switch (commandAdmin) {
                    case 1:
                        this->addMovieUI();
                        break;
                    case 2:
                        try {
                        this->removeMovieUI();
                        }
                        catch (RepoException e)
                    {
                        cout<<e.getMessage();
                    }
                        break;
                    case 3:
                        this->updateMovieUI();
                        break;
                    case 4:
                        this->displayAllMoviesRepo();
                        break;
                }
            }
                catch(RepoException e)
                {
                    cout<<e.getMessage();
                }
            }
        }
        else if (command == 2)
        {
            string ceva;
            cout<<"CSV or HTML?";
            getline(cin, ceva);
            CSVWatchlist csv = CSVWatchlist();
            HTMLWatchlist html = HTMLWatchlist();
            if (ceva == "csv")
                this->ctrl.setStorage(1, &csv);
            else this->ctrl.setStorage(2, &html);
            
            
            while (true)
            {
                UI::printUserMenu();
                int commandUser{0};
                cout<<"Input the command: ";
                cin>>commandUser;
                cout<<endl;
                cin.ignore();
                if (!commandUser)
                    break;
                switch (commandUser) {
                    case 1:
                        this->addMoviesByGenreUI();
                        break;
                    case 2:
                        this->deleteMovieWatchlistUI();
                        break;
                    case 3:
                    {
                        if (this->ctrl.getWatchList().isEmpty())
                        {
                            cout << "Nothing to play, the watchlist is empty." << endl;
                            continue;
                        }
                        this->ctrl.startWatchlist();
                        Movie m = this->ctrl.getWatchList().getCurrentMovie();
                        cout << "Now playing: " << m.getTitle() << " - " << m.getYear() << endl;
                        break;
                    }
                    case 4:
                    {
                        if (this->ctrl.getWatchList().isEmpty())
                        {
                            cout << "Nothing to play, the playlist is empty." << endl;
                            continue;
                        }
                        this->ctrl.nextMovieWatchlist();
                        Movie m = this->ctrl.getWatchList().getCurrentMovie();
                        cout << "Now playing: " << m.getTitle() << " - " << m.getYear() << endl;
                        break;
                    }
                }
            }
        }
    }
}
