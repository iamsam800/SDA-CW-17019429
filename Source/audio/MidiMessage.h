//
//  MidiMessage.h
//  JuceAudio
//
//  Created by Sam Scott on 05/02/2021.
//  Copyright © 2021 UWE. All rights reserved.
//


#pragma once
#include <JuceHeader.h>
#include "../Synth/BaseOscillator.hpp"


class MyMidiMessage : public MidiInputCallback
{
private:
 

public:
    
    MyMidiMessage();
     ~MyMidiMessage(); 
    
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;    
     void setPitchBendValue(float pitchWheel);
    float getMidiFrequency();
    int getMidiNoteNumber();
    float getMidiGain();
    float pitchBendGet();
    float getModWheelValue();
    
private:
    std::atomic<float> m_frequency = 0;
    std::atomic<int> m_notenum = 0;
    std::atomic<float> m_velocity = 0;
    
    //float m_pitchWheel = 0;
    std::atomic<float> m_pitchBendValue = 0;

    float m_modWheelValue = 0;
public:
    bool isNoteOn = false;
    bool isPitchWheel = false;
    
};
