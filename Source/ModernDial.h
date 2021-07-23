/*
  ==============================================================================

    ModernDial.h
    Created: 23 Jul 2021 12:45:48pm
    Author:  Kengo Suzuki

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomLookAndFeel.h"

class ModernDial  : public juce::Slider
{
public:
    ModernDial();
    ~ModernDial();
    
    void paint (juce::Graphics& g) override;
    
    void mouseDown (const juce::MouseEvent& event) override;
    void mouseUp (const juce::MouseEvent& event) override;
    
private:
    CustomLookAndFeel customLookAndFeel;
    
    juce::Colour grey      = juce::Colour::fromFloatRGBA (0.42f, 0.42f, 0.42f, 1.0f);
    juce::Colour blackGrey = juce::Colour::fromFloatRGBA (0.2f,  0.2f,  0.2f, 1.0f);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModernDial)
};
