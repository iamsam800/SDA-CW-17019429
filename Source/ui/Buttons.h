//
//  Buttons.h
//  JuceAudio - App
//
//  Created by Sam Scott on 05/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
#include "../../Source/ui/SynthUI.h"
#include "MetronomeUI.h"
#include "../../Source/audio/Audio.h"

class myButtons : public Component, public Button::Listener, public Slider::Listener
{
    
public:
    
    myButtons(); /* if object created and no arguments avaiable this constructor is used */
    
    myButtons(std::string name); /*  if object is created and nargument available, use this constructor */
    
    ~myButtons() = default;
    
    
    
    void resized() override;
   
    
    void buttonClicked (Button* Button) override;
    void buttonClicked();
    void sliderValueChanged (Slider* slider) override;
    
    void play();
    void stop();
   
    
    void setState(bool state);
    
    void getAudioReference(Audio& a);
    
   // TextButton getButton();
    
    std::string txt = "button text";
    
    TextButton thisButton;
    
    
    void getmetButtonState();
    
    enum class MetPlayState /**enum class for okay state */
    {
        Playing,
        Stopped
        
        
    };
    
private:
    
    int metbutval = 0;
    
    MetPlayState metplayState { MetPlayState::Stopped }; /** Play state dafaulted to not playing */
    Audio metronome;
    Audio *audioPtr;
    
    Slider Metronomesliders[2];
    Slider hello;
    TextButton metStartButton;
    TextButton metStopButton;
    Label metBpmLabel;
    Label metGainLabel;
    
};
