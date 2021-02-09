//
//  SawOscillator.hpp
//  JuceAudio - App
//
//  Created by Sam Scott on 15/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include "../../Source/Synth/SecondBaseOscillator.hpp"
#include <stdio.h>

class SawToothOscillatorTwo : public BaseOscillatorTwo
{
public:
    
    
    SawToothOscillatorTwo() = default;
    ~SawToothOscillatorTwo() = default;
    
    
protected:
    
    float renderWaveShape (float currentphase) override;
    
    
    
private:
    
    
    
    
};
