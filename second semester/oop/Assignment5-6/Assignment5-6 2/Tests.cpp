//
//  Tests.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 29/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Tests.hpp"
#include <assert.h>
#include "Movie.h"
#include "DynamicVector.hpp"
#include "Repository.hpp"
#include "Controller.hpp"

void Tests::TestMovie()
{
    Movie m{"wonder", "drama", 2017, 230, "un link provizoriu"};
    
    assert(m.getGenre() == "drama");
    assert(m.getTitle() == "wonder");
    assert(m.getLikes() == 230);
    assert(m.getYear() == 2017);
    m.increaseLikes();
    assert(m.getLikes() == 231);
    Movie n = m;
    assert(n == m);
    assert(m.getTrailer() == "un link provizoriu");
}

void Tests::testDynamicVector()
{
    DynamicVector<Movie> v{};
    v.add(Movie());
    assert(v.getSize() == 1);
    
    v = v - Movie();
    assert(v.getSize() == 0 );
    
    v.add(Movie());
    assert(v.getSize() == 1);
    
    for (int i = 0; i < v.getSize(); ++i)
        if (v[i] == Movie())
            v.remove(i);
    assert(v.getSize() == 0 );
    
    v.add(Movie());
    Movie m{"wonder", "drama", 2017, 230, "un link provizoriu"};
    v.update(0, m);
    assert(v[0].getTitle() == "wonder");
    
    assert(v.getAllElems() != NULL);
    
    v.add(Movie());
    v.add(Movie());
    assert(v.getSize() == 3);
}

void Tests::testRepo()
{
    Repository repo{};
    Movie m{"wonder", "drama", 2017, 230, "un link provizoriu"};
    Movie e{"ceva", "drama", 2002, 230, "un link provizoriu"};
    repo.addMovie(e);
    assert(repo.findMovie(e) != repo.getMovies().end());
    assert(repo.findMovie(m) == repo.getMovies().end());
    repo.addMovie(Movie());
    vector<Movie> v = repo.getMovies();
    assert(v.size() == 2);
    
    repo.removeMovie(m);
    assert(repo.getMovies().size() == 2);
    
    repo.removeMovie(Movie());
    assert(repo.getMovies().size() == 1);
    Movie n{"wonder", "comedy", 2017, 230, "un link provizoriu"};
    repo.updateMovie(m);
    assert(repo.getMovies()[0].getGenre() == "drama");
    repo.addMovie(Movie());
    repo.updateMovie(Movie("", "comedy", 0, 0, ""));
    assert(repo.getMovies()[0].getGenre() == "drama");
}

void Tests::testController()
{
    Repository repo{};
    WatchList watchlist{};
    CSVWatchlist csv{};
    Controller ctrl{repo, &csv};
    ctrl.addMovieToRepo("alt film", "comedy", 2018, 123, "soon to be link");
    
    assert(ctrl.getRepo().getMovies().size() == 1);
    
    ctrl.removeMovieFromRepo("alt film", 2018);
    assert(ctrl.getRepo().getMovies().size() == 0);
    
    ctrl.addMovieToRepo("alt film", "comedy", 2018, 123, "soon to be link");
    ctrl.updateMovieRepo("alt film", "drama", 2018, 340, "soon");
    assert(ctrl.getRepo().getMovies()[0].getGenre() == "drama");
    
    
}

void Tests::testAll()
{
    //TestMovie();
    //testDynamicVector();
    //testRepo();
    //testController();
}
