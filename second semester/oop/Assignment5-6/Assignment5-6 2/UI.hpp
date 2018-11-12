//
//  UI.hpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <string>
#include "Controller.hpp"

using namespace std;

class UI
{
private:
    Controller ctrl;
  
public:
    UI(const Controller& c): ctrl(c) {}
    
    void run();
private:
    static void printMenu();
    static void printAdminMenu();
    static void printUserMenu();
    
    void addMovieUI();
    void displayAllMoviesRepo();
    void removeMovieUI();
    void updateMovieUI();
    
    void addMoviesByGenreUI();
    void deleteMovieWatchlistUI();
};
