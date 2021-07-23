#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    setWantsKeyboardFocus (true);
    
    blueDial.setColour (juce::Slider::rotarySliderFillColourId, blue);
    greenDial.setColour (juce::Slider::rotarySliderFillColourId, green);
    yellowDial.setColour (juce::Slider::rotarySliderFillColourId, yellow);
    
    addAndMakeVisible (blueDial);
    addAndMakeVisible (greenDial);
    addAndMakeVisible (yellowDial);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (black);
}

void MainComponent::resized()
{
    blueDial.setBounds (120, 160, 80, 80);
    greenDial.setBounds (260, 160, 80, 80);
    yellowDial.setBounds (400, 160, 80, 80);
}
