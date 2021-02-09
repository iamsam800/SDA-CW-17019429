//
//  SquareOscillator.hpp
//  JuceAudio - App
//
//  Created by Sam Scott on 15/12/2020.
//  Copyright © 2020 UWE. All rights reserved.
//



#pragma once
#include "../../Source/Synth/SecondBaseOscillator.hpp"
#include <stdio.h>


class SquareOscillatorTwo : public BaseOscillatorTwo
{
    
public:
    
    SquareOscillatorTwo() = default;
    ~SquareOscillatorTwo() = default;
    
    
    
    
protected:
    float renderWaveShape (float currentphase) override;
    
private:
    
    
};
