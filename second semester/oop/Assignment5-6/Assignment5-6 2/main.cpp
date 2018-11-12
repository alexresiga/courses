//
//  main.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 23/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Movie.h"
#include "UI.hpp"
#include <string>
#include "Tests.hpp"
#include "RepositoryException.hpp"
#include <fstream>
#include "CSVWatchlist.hpp"

using namespace std;

int main()
{
    
    //Tests::testAll();
    
    Repository repo("movies.txt");
    CSVWatchlist csv{};
    Controller ctrl{repo, &csv};
    //ctrl.addMovieToRepo("gladiator", "comedy", 2018, 13, "http://www.imdb.com/title/tt5427194/?ref_=inth_ov_tt");
    //ctrl.addMovieToRepo("titanic", "drama", 2017, 23, "http://www.imdb.com/title/tt6644200/?ref_=vi_tr_mp_t_1");
    //ctrl.addMovieToRepo("jaws", "thriller", 2016, 67, "http://www.imdb.com/title/tt6644200/?ref_=vi_tr_mp_t_1");
    //ctrl.addMovieToRepo("rocky", "horror", 2015, 243, "http://www.imdb.com/title/tt0112573/?ref_=nv_sr_1");
//    ctrl.addMovieToRepo("alien", "comedy", 2014, 563, "http://www.imdb.com/title/tt6644200/?ref_=vi_tr_mp_t_1");
//    ctrl.addMovieToRepo("psycho", "comedy", 2016, 374, "http://www.imdb.com/title/tt5427194/?ref_=inth_ov_tt");
//    ctrl.addMovieToRepo("braveheart", "drama", 2018, 613, "http://www.imdb.com/title/tt0112573/?ref_=nv_sr_1");
//    ctrl.addMovieToRepo("shrek", "musical", 2017, 423, "http://www.imdb.com/title/tt0112573/?ref_=nv_sr_1");

    UI ui{ctrl};
    ui.run();
        
    return 0;
}
