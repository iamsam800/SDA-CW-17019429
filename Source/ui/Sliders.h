//
//  Sliders.h
//  JuceAudio
//
//  Created by Sam Scott on 05/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
#include "SynthUI.h"
#include "../../Source/Synth/BaseOscillator.hpp"
#include "../../Source/Synth/SecondBaseOscillator.hpp"
#include "../../Source/audio/Audio.h"
class mySliders : public Component,  public Slider::Listener
{
public:
    
    mySliders(); /* if object created and no arguments avaiable this constructor is used */
    
    
    
    ~mySliders() = default;
    
    void sliderMoved();
   
    void sliderValueChanged (Slider* slider) override;
    
    void resized() override;
  
    
    
    
  
    
    
    
    void getReference(Audio &a);
   
    
    
   
    
    
    
private:
   
    Audio* audioPTR;

    
    Slider envSliders[4];
    Label envLabel[4];
    Slider fmSliders[2];
    Slider filterSliders[2];
    Label raidialLabel[4];
    
    /*Label envAttack;
    Label envDecay;
    Label envSustain;
    Label envRelease;*/
};
