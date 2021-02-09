//
//  SquareOscillator.hpp
//  JuceAudio - App
//
//  Created by Sam Scott on 30/12/2020.
//  Copyright © 2020 UWE. All rights reserved.
//



#pragma once
#include "BaseOscillator.hpp"
#include <stdio.h>


class SquareOscillator : public BaseOscillator
{
    
public:
    
    SquareOscillator() = default;
    ~SquareOscillator() = default;
    
    
    
    
protected:
    float renderWaveShape (float currentphase) override;
    
private:
    
   
};
