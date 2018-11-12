//
//  main.cpp
//  wannabe2
//
//  Created by Alex Resiga on 16/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "UI.hpp"

int main()
{
    Person p{"mihai"};
    MedicalAnalysis* m1 = new BMI{ "2018.03.12", 12 };
    MedicalAnalysis* m3 = new BP{ "2017.03.12", 12, 100};
    MedicalAnalysis* m2 = new BMI{ "2019.03.12", 10 };
    MedicalAnalysis* m4 = new BMI{ "2019.07.12", 20 };
    p.addAnalysis(m1);
    p.addAnalysis(m2);
    p.addAnalysis(m3);
    p.addAnalysis(m4);
    UI ui{ p };
    ui.run();
    return 0;
}
