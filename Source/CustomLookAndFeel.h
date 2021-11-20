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
    struct CustomLabel : public juce::Label
    {
        static juce::String initialPressedKey;

        juce::TextEditor* createEditorComponent() override
        {
            auto* ed = juce::Label::createEditorComponent();

            ed->setJustification (juce::Justification::centred);
            ed->setColour (juce::TextEditor::backgroundColourId, juce::Colours::transparentWhite);
            ed->setInputRestrictions (5, "0123456789.");
            ed->setIndents (4, 0);

            return ed;
        }

        void editorShown (juce::TextEditor* editor) override
        {
            getParentComponent()->setMouseCursor (juce::MouseCursor::NoCursor);
            editor->clear();
            editor->setText (initialPressedKey);
        }

        void editorAboutToBeHidden (juce::TextEditor * ed) override
        {
            getParentComponent()->setMouseCursor (juce::MouseCursor::NormalCursor);
        }
    };
    
    CustomLookAndFeel();
    ~CustomLookAndFeel();
        
    juce::Slider::SliderLayout getSliderLayout (juce::Slider& slider) override;
           
    void drawRotarySlider (juce::Graphics&, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle,
                           float rotaryEndAngle, juce::Slider&) override;
    
    CustomLabel* createSliderTextBox (juce::Slider& slider) override;
    
    juce::CaretComponent* createCaretComponent (juce::Component* keyFocusOwner) override;
};
