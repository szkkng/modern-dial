/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 23 Jul 2021 12:48:44pm
    Author:  Kengo Suzuki

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../Resources/FuturaMedium.h"
#include "CustomColours.h"

class CustomLookAndFeel : public juce::LookAndFeel_V4
{
public:
    CustomLookAndFeel();
    ~CustomLookAndFeel();
        
    juce::Slider::SliderLayout getSliderLayout (juce::Slider& slider) override;
           
    void drawRotarySlider (juce::Graphics&, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle,
                           float rotaryEndAngle, juce::Slider&) override;
    
    juce::Label* createSliderTextBox (juce::Slider& slider) override;
};
