//
//  SawOscillator.hpp
//  JuceAudio - App
//
//  Created by Sam Scott on 09/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include "BaseOscillator.hpp"
#include <stdio.h>

class SawToothOscillator : public BaseOscillator
{
public:
    
    
    SawToothOscillator() = default;
    ~SawToothOscillator() = default;
    
    
protected:
    
    float renderWaveShape (float currentphase) override;
    
    
    
private:
    
    
    
    
};
