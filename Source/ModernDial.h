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
#include "CustomColours.h"

class ModernDial  : public juce::Slider
{
public:
    ModernDial();
    ~ModernDial();
    
    void paint (juce::Graphics& g) override;
    
    void mouseDown (const juce::MouseEvent& event) override;
    void mouseUp (const juce::MouseEvent& event) override;
    
    bool keyPressed (const juce::KeyPress& k) override;
    
private:
    CustomLookAndFeel customLookAndFeel;
};
