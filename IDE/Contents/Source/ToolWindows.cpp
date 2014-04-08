/*
 Copyright (C) 2012 by Ivan Safrin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */
 
#include "ToolWindows.h"
#include "PolycodeToolLauncher.h"

TextInputPopup::TextInputPopup() : UIWindow(L"", 300, 80) {
	
	textInput = new UITextInput(false, 290, 12);	
	addChild(textInput);
	textInput->setPosition(padding, 35);
		
	cancelButton = new UIButton(L"Cancel", 100);
	cancelButton->addEventListener(this, UIEvent::CLICK_EVENT);
	addChild(cancelButton);
	cancelButton->setPosition(padding+300-100-100-10, 64);		
	
	okButton = new UIButton(L"OK", 100);
	okButton->addEventListener(this, UIEvent::CLICK_EVENT);
	addChild(okButton);
	okButton->setPosition(padding+300-100, 64);
	
	closeOnEscape = true;

}

void TextInputPopup::setCaption(String caption) {
	setWindowCaption(caption);
}

String TextInputPopup::getValue() {
	return textInput->getText();
}

void TextInputPopup::setValue(String value) {
	textInput->setText(value);
	focusChild(textInput);	
}

void TextInputPopup::handleEvent(Event *event) {
	if(event->getEventType() == "UIEvent") {
		if(event->getEventCode() == UIEvent::CLICK_EVENT) {
			if(event->getDispatcher() == okButton) {
				dispatchEvent(new UIEvent(), UIEvent::OK_EVENT);						
			}
			
			if(event->getDispatcher() == cancelButton) {
				dispatchEvent(new UIEvent(), UIEvent::CLOSE_EVENT);				
			}									
		}
	}
	UIWindow::handleEvent(event);	
}


TextInputPopup::~TextInputPopup() {
	
}

YesNoPopup::YesNoPopup() : UIWindow(L"", 300, 80) {
	
	captionLabel = new UILabel("This is a caption", 12);	
	addChild(captionLabel);
	captionLabel->setPosition(padding, 35);
		
	buttonAnchor = new Entity();
	buttonAnchor->processInputEvents = true;
	addChild(buttonAnchor);
			
	cancelButton = new UIButton(L"No", 100);
	cancelButton->addEventListener(this, UIEvent::CLICK_EVENT);
	buttonAnchor->addChild(cancelButton);
	cancelButton->setPosition(0, 60);		
	
	okButton = new UIButton(L"Yes", 100);
	okButton->addEventListener(this, UIEvent::CLICK_EVENT);
	buttonAnchor->addChild(okButton);
	okButton->setPosition(120, 60);
	
	closeOnEscape = true;

}

void YesNoPopup::setCaption(String caption) {
	captionLabel->setText(caption);
	
	Number windowSize = captionLabel->getWidth() + 50;
	if(windowSize < 400)
		windowSize = 400;
	setWindowSize(windowSize, 80);
	captionLabel->setPosition(padding + (windowSize - captionLabel->getWidth()) / 2.0, 35);
	buttonAnchor->setPosition(padding + ((windowSize - 220) / 2.0), 0);
}

void YesNoPopup::handleEvent(Event *event) {
	if(event->getEventType() == "UIEvent") {
		if(event->getEventCode() == UIEvent::CLICK_EVENT) {
			if(event->getDispatcher() == okButton) {
				dispatchEvent(new UIEvent(), UIEvent::OK_EVENT);						
			}
			
			if(event->getDispatcher() == cancelButton) {
				dispatchEvent(new UIEvent(), UIEvent::CLOSE_EVENT);
				dispatchEvent(new UIEvent(), UIEvent::CANCEL_EVENT);				
			}									
		}
	}
	UIWindow::handleEvent(event);	
}


YesNoPopup::~YesNoPopup() {
	
}

YesNoCancelPopup::YesNoCancelPopup() : UIWindow(L"", 300, 80) {
	
	captionLabel = new UILabel("This is a caption", 12);	
	addChild(captionLabel);
	captionLabel->setPosition(padding, 35);
		
	buttonAnchor = new Entity();
	buttonAnchor->processInputEvents = true;
	addChild(buttonAnchor);
	
	noButton = new UIButton(L"No", 100);
	noButton->addEventListener(this, UIEvent::CLICK_EVENT);
	buttonAnchor->addChild(noButton);
	noButton->setPosition(0, 60);		
	
	okButton = new UIButton(L"Yes", 100);
	okButton->addEventListener(this, UIEvent::CLICK_EVENT);
	buttonAnchor->addChild(okButton);
	okButton->setPosition(120, 60);
	
	cancelButton = new UIButton(L"Cancel", 100);
	cancelButton->addEventListener(this, UIEvent::CLICK_EVENT);
	buttonAnchor->addChild(cancelButton);
	cancelButton->setPosition(240, 60);		

	closeOnEscape = true;

}

void YesNoCancelPopup::setCaption(String caption) {
	captionLabel->setText(caption);
	Number windowSize = captionLabel->getWidth() + 50;
	if(windowSize < 400)
		windowSize = 400;	
	setWindowSize(windowSize, 80);
	captionLabel->setPosition(padding + (windowSize - captionLabel->getWidth()) / 2.0, 35);
	buttonAnchor->setPosition(padding + ((windowSize - 360) / 2.0), 0);
}

void YesNoCancelPopup::handleEvent(Event *event) {
	if(event->getEventType() == "UIEvent") {
		if(event->getEventCode() == UIEvent::CLICK_EVENT) {
			if(event->getDispatcher() == okButton) {
				dispatchEvent(new UIEvent(), UIEvent::YES_EVENT);						
			}
			
			if(event->getDispatcher() == noButton) {
				dispatchEvent(new UIEvent(), UIEvent::NO_EVENT);
			}									
			
			if(event->getDispatcher() == cancelButton) {
				dispatchEvent(new UIEvent(), UIEvent::CLOSE_EVENT);
				dispatchEvent(new UIEvent(), UIEvent::CANCEL_EVENT);				
			}									
			
		}
	}
	UIWindow::handleEvent(event);	
}


YesNoCancelPopup::~YesNoCancelPopup() {
	
}

AssetImporterWindow::AssetImporterWindow() : UIWindow("3D Asset Importer", 650, 280) {
	filesToImportLabel = new UILabel("Files that will be imported:", 12);
	addChild(filesToImportLabel);
	filesToImportLabel->setPosition(padding, 35);
	
	filesAnchor = new Entity();	
		
	filesScroller = new UIScrollContainer(filesAnchor, true, true, 270, 200);
	addChild(filesScroller);
	filesScroller->setPosition(padding, 60);
		
	cancelButton = new UIButton(L"Cancel", 100);
	cancelButton->addEventListener(this, UIEvent::CLICK_EVENT);
	addChild(cancelButton);
	cancelButton->setPosition(padding+650-100-100-10-10, 265);
	
	okButton = new UIButton(L"OK", 100);
	okButton->addEventListener(this, UIEvent::CLICK_EVENT);
	addChild(okButton);
	okButton->setPosition(padding+650-100-10, 265);
	
	closeOnEscape = true;

	prefixInput = new UITextInput(false, 200, 16);
	prefixInput->setPosition(290, 30);
	addChild(prefixInput); 
	prefixInput->addEventListener(this, UIEvent::CHANGE_EVENT);
		
	usePrefixCheckbox = new UICheckBox("Custom filename prefix", false);
	usePrefixCheckbox->setPosition(290, 60);
	addChild(usePrefixCheckbox);
	usePrefixCheckbox->addEventListener(this, UIEvent::CHANGE_EVENT);
	
	addMeshesCheckbox = new UICheckBox("Add all meshes to a single mesh", false);
	addMeshesCheckbox->setPosition(290, 90);
	addChild(addMeshesCheckbox); 
	addMeshesCheckbox->addEventListener(this, UIEvent::CHANGE_EVENT);
	
	generateNormalsCheckbox = new UICheckBox("Generate normals", false);
	generateNormalsCheckbox->setPosition(290, 120);
	addChild(generateNormalsCheckbox);
    
	generateTangensCheckbox = new UICheckBox("Generate tangents", true);
	generateTangensCheckbox->setPosition(290, 150);
	addChild(generateTangensCheckbox);

	swapZYAxisCheckbox = new UICheckBox("Swap Z/Y axis (e.g. for Blender)", false);
	swapZYAxisCheckbox->setPosition(290, 180);
	addChild(swapZYAxisCheckbox);
    
    exportNormals = new UICheckBox("Vertex normals", true);
	exportNormals->setPosition(520, 30);
	addChild(exportNormals);
    
    exportTangents = new UICheckBox("Vertex tangents", true);
	exportTangents->setPosition(520, 60);
	addChild(exportTangents);
    
    exportColors = new UICheckBox("Vertex colors", false);
	exportColors->setPosition(520, 90);
	addChild(exportColors);
    
    exportBoneWeights = new UICheckBox("Bone weights", false);
	exportBoneWeights->setPosition(520, 120);
	addChild(exportBoneWeights);
    
    exportUVs = new UICheckBox("UV coordinates", true);
	exportUVs->setPosition(520, 150);
	addChild(exportUVs);
    
    exportSecondaryUVs = new UICheckBox("Secondary UVs", false);
	exportSecondaryUVs->setPosition(520, 180);
	addChild(exportSecondaryUVs);

    exportScene = new UICheckBox("Export Entity file", false);
	exportScene->setPosition(520, 210);
	addChild(exportScene);
    
}

void AssetImporterWindow::handleEvent(Event *event) {
    if(!enabled) {
        return;
    }
	if(event->getDispatcher() == okButton) {
	
		String prefixString;
		if(usePrefixCheckbox->isChecked() && prefixInput->getText() != "") {
			prefixString = prefixInput->getText().replace(" ", "_");
		}
		PolycodeToolLauncher::importAssets(file, folder, addMeshesCheckbox->isChecked(), prefixString, swapZYAxisCheckbox->isChecked(), generateNormalsCheckbox->isChecked(), generateTangensCheckbox->isChecked(), false, exportNormals->isChecked(), exportTangents->isChecked(), exportColors->isChecked(), exportBoneWeights->isChecked(), exportUVs->isChecked(), exportSecondaryUVs->isChecked(), exportScene->isChecked());
	
		dispatchEvent(new UIEvent(), UIEvent::OK_EVENT);
		dispatchEvent(new UIEvent(), UIEvent::CLOSE_EVENT);	
	} else if(event->getDispatcher() == cancelButton) {
		dispatchEvent(new UIEvent(), UIEvent::CLOSE_EVENT);
	}

	UIWindow::handleEvent(event);
}

void AssetImporterWindow::clearFiles() {
	for(int i=0; i < fileLabels.size(); i++) {
		filesAnchor->removeChild(fileLabels[i]);
		delete fileLabels[i];
	}
	fileLabels.clear();
	filesScroller->setContentSize(0,0);
}

void AssetImporterWindow::addFile(String fileName) {
	UILabel *fileLabel = new UILabel(fileName, 12);
	filesAnchor->addChild(fileLabel);
	fileLabel->setPosition(0.0, 14 * fileLabels.size());

	if(fileLabel->getWidth() > filesScroller->getContentSize().x) {
		filesScroller->setContentSize(fileLabel->getWidth(), (fileLabels.size()+1) * 14);
	} else {
		filesScroller->setContentSize(filesScroller->getContentSize().x, (fileLabels.size()+1) * 14);	
	}	
	filesScroller->setScrollValue(0, 0);
	
	fileLabels.push_back(fileLabel);
}

void AssetImporterWindow::setSourceFileAndTargetFolder(String file, String folder) {
	this->file = file;
	this->folder = folder;
	refreshPreview();
}

void AssetImporterWindow::refreshPreview() {
	String prefixString;
	if(usePrefixCheckbox->isChecked() && prefixInput->getText() != "") {
		prefixString = prefixInput->getText().replace(" ", "_");
	}
	String fileList = PolycodeToolLauncher::importAssets(file, folder, addMeshesCheckbox->isChecked(), prefixString, swapZYAxisCheckbox->isChecked(), generateNormalsCheckbox->isChecked(), generateTangensCheckbox->isChecked(), true, false, false, false, false, false, false, false);
	setFilesToImport(fileList);		
}

void AssetImporterWindow::setFilesToImport(String files) {	
	clearFiles();
	
	if(files == "") {
		addFile("NO");
		addFile("IMPORTABLE");
		addFile("ASSETS");
	}else {
		std::vector<String> splitFiles = files.split("\n");
		for(int i=0; i < splitFiles.size(); i++) {
			addFile(splitFiles[i]);
		}
	}
}

AssetImporterWindow::~AssetImporterWindow() {

}
