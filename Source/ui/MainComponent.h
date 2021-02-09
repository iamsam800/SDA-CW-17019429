#pragma once

#include <JuceHeader.h>
#include "../audio/Audio.h"
#include "../../Source/audio/Metronome.h"
#include "../../Source/ui/Sliders.h"
#include <iostream>
#include <array>
#include "../../Source/ui/Buttons.h"
#include "../../Source/Synth/BaseOscillator.hpp"
#include "../../Source/Synth/SecondBaseOscillator.hpp"
#include "../../Source/ui/SynthUI.h"
#include "MetronomeUI.h"
//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainComponent   :
                        public MenuBarModel,
                        public Button::Listener,

                        public Component


                    

{
public:
    //==============================================================================
    /** Constructor */
    MainComponent (Audio& a);
    
    /** Destructor */
    ~MainComponent() override;
    
    //Comoponent====================================================================
    void resized() override;
    void paint (Graphics&) override;
    
    void buttonClicked (Button* Button) override;
   
    
    
    
  
    
    //MenuBarEnums/MenuBarModel=====================================================
    enum Menus
    {
        FileMenu = 0,
        
        NumMenus
    };
    
    enum FileMenuItems
    {
        AudioPrefs = 1,
        
        NumFileItems
    };
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex (int topLevelMenuIndex, const String& menuName) override;
    void menuItemSelected (int menuItemID, int topLevelMenuIndex) override;
    
    
    int getmetButtonState();
    
    enum class MetPlayState /**enum class for okay state */
    {
        Playing,
        Stopped
        
        
    };
    
private:
     OtherLookAndFeel f;
    myButtons UI;
    mySliders OscilUI;
    
    Audio& audio;
    MetPlayState metplayState { MetPlayState::Stopped }; /** Play state dafaulted to not playing */
    
    int ButtonToggle = 0;
    int sliderVal = 0;
    bool metbuttonToggle = { true };
    int metbutval = 0;
    
   
   
    
    
   
    
    
   
    
    
   
    

    
   
    /**Buttons, objects  of myButtons button class */
  
   myButtons waveButton[4] = {myButtons("Sine Wave"), myButtons("Square Wave"), myButtons("Triangle Wave"), myButtons("Saw-Tooth Wave")};
   
    /**Objects of oscillator wave types */
   SinOscillator sin;
    SquareOscillator square;
    SawToothOscillator saw;
    TriangleOscillator triangle;
    
    SinOscillatorTwo sin2;
    SquareOscillatorTwo square2;
    TriangleOscillatorTwo triangle2;
    SawToothOscillatorTwo saw2;
   
  
    float modwheelval = 0;
//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
