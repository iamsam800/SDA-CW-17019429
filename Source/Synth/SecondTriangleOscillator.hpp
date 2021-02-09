//
//  TriangleOscillator.hpp
//  JuceAudio - App
//
//  Created by Sam Scott on 15/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include "../../Source/Synth/SecondBaseOscillator.hpp"
#include <stdio.h>


class TriangleOscillatorTwo : public BaseOscillatorTwo
{
public:
    
    TriangleOscillatorTwo() = default;
    ~TriangleOscillatorTwo() = default;
    
protected:
    
    float renderWaveShape (float currentphase) override;
    
private:
};
