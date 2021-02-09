//
//  TriangleOscillator.hpp
//  JuceAudio - App
//
//  Created by Sam Scott on 09/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#include "BaseOscillator.hpp"
#include <stdio.h>

 
class TriangleOscillator : public BaseOscillator
{
public:
    
    TriangleOscillator() = default;
    ~TriangleOscillator() = default;
    
protected:
    
    float renderWaveShape (float currentphase) override;
    
private:
};
