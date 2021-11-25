/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 23 Jul 2021 12:48:44pm
    Author:  Kengo Suzuki

  ==============================================================================
*/

#include "CustomLookAndFeel.h"

juce::String CustomLookAndFeel::CustomLabel::initialValue = "";

CustomLookAndFeel::CustomLookAndFeel()
{
    auto futuraMediumFont = juce::Typeface::createSystemTypefaceFor (FuturaMedium::FuturaMedium_otf, FuturaMedium::FuturaMedium_otfSize);
    setDefaultSansSerifTypeface (futuraMediumFont);
};

CustomLookAndFeel::~CustomLookAndFeel() {};

juce::Slider::SliderLayout CustomLookAndFeel::getSliderLayout (juce::Slider& slider)
{
    auto localBounds = slider.getLocalBounds();
    
    juce::Slider::SliderLayout layout;

    layout.textBoxBounds = localBounds.withY (-1);
    layout.sliderBounds = localBounds;

    return layout;
}

void CustomLookAndFeel::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                                          const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider)
{
    auto fill = slider.findColour (juce::Slider::rotarySliderFillColourId);

    auto bounds = juce::Rectangle<float> (x, y, width, height).reduced (2.0f);
    auto radius = juce::jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = radius * 0.085f;
    auto arcRadius = radius - lineW * 1.6f;
    
    juce::Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);
    
    g.setColour (CustomColours::blackGrey);
    g.strokePath (backgroundArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
    
    juce::Path valueArc;
    valueArc.addCentredArc (bounds.getCentreX(),
                            bounds.getCentreY(),
                            arcRadius,
                            arcRadius,
                            0.0f,
                            rotaryStartAngle,
                            toAngle,
                            true);
        
    g.setColour (fill);
    g.strokePath (valueArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

    juce::Path thumb;
    auto thumbWidth = lineW * 2.0f;
    
    thumb.addRectangle (-thumbWidth / 2, -thumbWidth / 2, thumbWidth, radius + lineW);
    
    g.setColour (CustomColours::creamWhite);
    g.fillPath (thumb, juce::AffineTransform::rotation (toAngle + 3.12f).translated (bounds.getCentre()));

    g.fillEllipse (bounds.reduced (radius * 0.25));
}

CustomLookAndFeel::CustomLabel* CustomLookAndFeel::createSliderTextBox (juce::Slider& slider)
{
    auto* l = new CustomLabel();

    l->setJustificationType (juce::Justification::centred);
    l->setColour (juce::Label::textColourId, slider.findColour (juce::Slider::textBoxTextColourId));
    l->setColour (juce::Label::textWhenEditingColourId, slider.findColour (juce::Slider::textBoxTextColourId));
    l->setColour (juce::Label::outlineWhenEditingColourId, juce::Colours::transparentWhite);
    l->setInterceptsMouseClicks (false, false);
    l->setFont (16.0f);

    return l;
}

juce::CaretComponent* CustomLookAndFeel::createCaretComponent (juce::Component* keyFocusOwner)
{
    auto caret = new juce::CaretComponent (keyFocusOwner);

    caret->setColour (juce::CaretComponent::caretColourId, juce::Colours::red);

    return caret;
}
