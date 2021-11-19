#pragma once

#include <JuceHeader.h>
#include "CustomColours.h"
#include "CustomLookAndFeel.h"
#include "ModernDial.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    ModernDial blueDial, yellowDial, greenDial;
    
    CustomLookAndFeel customLookAndFeel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
