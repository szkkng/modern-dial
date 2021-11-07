/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 23 Jul 2021 12:48:44pm
    Author:  Kengo Suzuki

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

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
    
private:
    juce::Colour blue       = juce::Colour::fromFloatRGBA (0.43f, 0.83f, 1.0f,  1.0f);
    juce::Colour creamWhite = juce::Colour::fromFloatRGBA (0.96f, 0.98f, 0.89f, 1.0f);
    juce::Colour grey       = juce::Colour::fromFloatRGBA (0.42f, 0.42f, 0.42f, 1.0f);
    juce::Colour blackGrey  = juce::Colour::fromFloatRGBA (0.2f,  0.2f,  0.2f,  1.0f);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomLookAndFeel);
};
