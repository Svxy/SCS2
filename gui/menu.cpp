#include "menu.hpp"

#include "../features/entry.hpp"
#include "../util/config.hpp"


void imGuiMenu::setStyle() {
    // Setting styles
    ImGuiStyle* style = &ImGui::GetStyle();

    // Sizes
    style->FramePadding = ImVec2(8, 6);
    style->FrameBorderSize = 1.2f;
    style->FrameRounding = 4.0f;
    
    style->WindowPadding = ImVec2(10, 10);
    
    style->GrabRounding = 4.0f;
    style->GrabMinSize = 20.f;

    style->ButtonTextAlign = ImVec2(0.5, 0.5);

    style->ItemSpacing = ImVec2(10, 8);
    style->ItemInnerSpacing = ImVec2(8, 6);

    // Colors
    ImVec4* colors = style->Colors;
    
    ImColor darkRed = ImColor(120, 0, 0, 255);
    ImColor lightRed = ImColor(255, 36, 36, 255);
    ImColor darkGrey = ImColor(40, 40, 40, 255);
    ImColor grey = ImColor(60, 60, 60, 255);
    ImColor lightGrey = ImColor(80, 80, 80, 255);
    ImColor white = ImColor(255, 255, 255, 255);

    colors[ImGuiCol_Text] = white;
    colors[ImGuiCol_TextDisabled] = grey;

    colors[ImGuiCol_WindowBg] = darkGrey;
    colors[ImGuiCol_ChildBg] = darkGrey;
    colors[ImGuiCol_PopupBg] = darkGrey;
    
    colors[ImGuiCol_Border] = lightGrey;
    colors[ImGuiCol_BorderShadow] = darkRed;

    colors[ImGuiCol_FrameBg] = grey;
    colors[ImGuiCol_FrameBgHovered] = lightRed;
    colors[ImGuiCol_FrameBgActive] = darkRed;

    colors[ImGuiCol_TitleBg] = darkRed;
    colors[ImGuiCol_TitleBgActive] = darkRed;
    colors[ImGuiCol_TitleBgCollapsed] = grey;

    colors[ImGuiCol_MenuBarBg] = grey;
    colors[ImGuiCol_ScrollbarBg] = grey;
    colors[ImGuiCol_ScrollbarGrab] = lightRed;
    colors[ImGuiCol_ScrollbarGrabHovered] = lightRed;
    colors[ImGuiCol_ScrollbarGrabActive] = darkRed;
    
    colors[ImGuiCol_CheckMark] = darkRed;
    colors[ImGuiCol_SliderGrab] = darkRed;
    colors[ImGuiCol_SliderGrabActive] = lightRed;

    colors[ImGuiCol_Button] = darkRed;
    colors[ImGuiCol_ButtonHovered] = lightRed;
    colors[ImGuiCol_ButtonActive] = darkRed;

    colors[ImGuiCol_Header] = darkRed;
    colors[ImGuiCol_HeaderHovered] = lightRed;
    colors[ImGuiCol_HeaderActive] = darkRed;

    colors[ImGuiCol_Separator] = darkRed;
    colors[ImGuiCol_SeparatorHovered] = lightRed;
    colors[ImGuiCol_SeparatorActive] = darkRed;

    colors[ImGuiCol_ResizeGrip] = darkRed;
    colors[ImGuiCol_ResizeGripHovered] = lightRed;
    colors[ImGuiCol_ResizeGripActive] = darkRed;

    colors[ImGuiCol_PlotLines] = darkRed;
    colors[ImGuiCol_PlotLinesHovered] = lightRed;
    colors[ImGuiCol_PlotHistogram] = darkRed;
    colors[ImGuiCol_PlotHistogramHovered] = lightRed;

    colors[ImGuiCol_TextSelectedBg] = lightRed;
    colors[ImGuiCol_DragDropTarget] = lightRed;

    colors[ImGuiCol_NavHighlight] = lightRed;
    colors[ImGuiCol_NavWindowingHighlight] = lightRed;
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(darkRed.Value.x, darkRed.Value.y, darkRed.Value.z, 0.7f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(darkRed.Value.x, darkRed.Value.y, darkRed.Value.z, 0.7f);
}


void imGuiMenu::verticalSplitter(float width,float height) {
	ImGui::SameLine();
	ImGui::InvisibleButton("vsplitter", ImVec2(8.0f, height));
	if (ImGui::IsItemActive())
		width += ImGui::GetIO().MouseDelta.x;
	ImGui::SameLine();
}


void imGuiMenu::horizontalSplitter(float height) {
	ImGui::InvisibleButton("hsplitter", ImVec2(-1, 8.0f));
	if (ImGui::IsItemActive())
		height += ImGui::GetIO().MouseDelta.y;
}


void imGuiMenu::espRender() {
	if (tabCount == 1) {

		ImGui::BeginChild("Features", ImVec2(imGuiMenu::widthSeparatorInt, imGuiMenu::heightSeparatorInt), true);
		ImGui::PushFont(imGuiMenu::titleText);
		ImGui::Text("Attributes");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("ESP toggle", &espConf.state);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		if (espConf.state) {
			ImGui::Checkbox("Gradient Line", &espConf.gradient);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Bounding Box", &espConf.boundBox);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Player name", &espConf.isPawnName);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Weapon name", &espConf.isPawnGun);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Health bar", &espConf.isHealthBar);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Skeleton", &espConf.skeleton);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Head", &espConf.head);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Joints", &espConf.joint);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Distance", &espConf.distance);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Snap lines", &espConf.snapLines);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		}
		ImGui::Checkbox("C4 ESP Toggle", &espConf.c4State);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		if (espConf.c4State) {
			ImGui::Checkbox("Gradient", &espConf.c4Gradient);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::Checkbox("Carrier", &espConf.c4Carrier);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		}
		ImGui::EndChild();

		verticalSplitter(imGuiMenu::widthSeparatorInt, imGuiMenu::heightSeparatorInt);

		ImGui::BeginChild("Feature options", ImVec2(0, imGuiMenu::heightSeparatorInt), true);
		ImGui::PushFont(imGuiMenu::titleText);
		ImGui::Text("Feature options");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::PushFont(imGuiMenu::subTitleText);
		ImGui::Text("Main options");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Visibility check", &espConf.checkSpotted);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::PushFont(imGuiMenu::subTitleText);
		ImGui::Text("Health options");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("HP counter", &espConf.hpCounter);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::PushFont(imGuiMenu::subTitleText);
		ImGui::Text("Box options");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Colour fill", &espConf.filledBox);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::SliderFloat("Fill alpha", &espConf.filledBoxAlpha, 0.f, 1.f);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::SliderFloat("Width", &espConf.width, 1.f, 5.f);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::SliderFloat("Thickness", &espConf.boundBoxThickness, 1.f, 3.f);
		if (espConf.c4State) {
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::SliderFloat("C4 Thickness", &espConf.c4Thickness, 1.f, 3.f);
		}
		ImGui::EndChild();

		horizontalSplitter(HEIGHT);

		ImGui::BeginChild("Colours", ImVec2(0, 0), true);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::PushFont(imGuiMenu::titleText);
		ImGui::Text("Colours");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::ColorEdit3("Box spotted", (float*)&espConf.spottedColours);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::ColorEdit3("Box not spotted", (float*)&espConf.notSpottedColours);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::ColorEdit3("Atrributes colour", (float*)&espConf.attributeColours);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::ColorEdit3("Corner colours", (float*)&espConf.cornerColours);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		if (espConf.gradient) {
			ImGui::ColorEdit3("Corner gradient", (float*)&espConf.cornerGradient);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		}
		ImGui::ColorEdit3("Skeleton colour", (float*)&espConf.skeletonColours);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::ColorEdit3("Head colours", (float*)&espConf.headColours);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::ColorEdit3("Joint colours", (float*)&espConf.jointColours);
		if (espConf.c4State) {
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			ImGui::ColorEdit3("C4 Colors", (float*)&espConf.c4Colors);
			if (espConf.c4Gradient) {
				ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
				ImGui::ColorEdit3("C4 Gradient", (float*)&espConf.c4ColorsGradient);
			}
		}

		ImGui::EndChild();
	}
}

void imGuiMenu::aimRender() {
	if (tabCount == 2) {

		ImGui::BeginChild("Aimbot", ImVec2(imGuiMenu::widthSeparatorInt, imGuiMenu::heightSeparatorInt), true);
		ImGui::PushFont(imGuiMenu::titleText);
		ImGui::Text("Aimbot");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Aimbot", &aimConf.state);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Fov circle", &aimConf.fovCircle);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Visibility check", &aimConf.checkSpotted);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::SliderFloat("FOV", &aimConf.fov, 1.f, 25.f);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::SliderFloat("Smoothing", &aimConf.smoothing, 1.f, 5.f);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::SliderFloat("Aim Sensibility", &aimConf.sens, 0.1f, 8.f);
		ImGui::EndChild();

		verticalSplitter(imGuiMenu::widthSeparatorInt, imGuiMenu::heightSeparatorInt);

		ImGui::BeginChild("Misc", ImVec2(0, imGuiMenu::heightSeparatorInt), true);
		ImGui::PushFont(imGuiMenu::titleText);
		ImGui::Text("Miscellaneous aim functions");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Recoil Control", &aimConf.rcs);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Player lock", &aimConf.playerLock);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Trigger Bot", &aimConf.trigger);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Trigger bot hot key", &aimConf.isHotTrigger);
		if (aimConf.isHotTrigger) {
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
			if (ImGui::BeginCombo("Hot key", aimConf.hotKey[aimConf.hotSelectTrigger].c_str())) {
				for (int i = 0; i < aimConf.hotKey.size(); ++i) {
					const bool isSelected = (aimConf.hotTrigger == i);

					if (ImGui::Selectable(aimConf.hotKey[i].c_str(), isSelected)) {
						aimConf.hotSelectTrigger = i;
					}

					if (isSelected) {
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}
		}
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		if (ImGui::BeginCombo("Aimbot Preference", aimConf.aimModes[aimConf.aimMode].c_str())) {
			for (int i = 0; i < aimConf.aimModes.size(); ++i) {
				const bool isSelected = (aimConf.aimMode == i);

				if (ImGui::Selectable(aimConf.aimModes[i].c_str(), isSelected)) {
					aimConf.aimMode = i;
				}

				if (isSelected) {
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}
		ImGui::EndChild();

		horizontalSplitter(HEIGHT);

		ImGui::BeginChild("Hitboxes", ImVec2(0, 0), true);
		ImGui::PushFont(imGuiMenu::titleText);
		ImGui::Text("Hitboxes");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		if (ImGui::BeginCombo("Hit box", aimConf.bones[aimConf.boneSelect].c_str())) {
			for (int i = 0; i < aimConf.bones.size(); ++i) {
				const bool isSelected = (aimConf.bone == i);

				if (ImGui::Selectable(aimConf.bones[i].c_str(), isSelected)) {
					aimConf.boneSelect = i;
				}

				if (isSelected) {
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Aim bot hot key", &aimConf.isHotAim);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		if (aimConf.isHotAim) {
			if (ImGui::BeginCombo("Hot key", aimConf.hotKey[aimConf.hotSelectAim].c_str())) {
				for (int i = 0; i < aimConf.hotKey.size(); ++i) {
					const bool isSelected = (aimConf.hotAim == i);

					if (ImGui::Selectable(aimConf.hotKey[i].c_str(), isSelected)) {
						aimConf.hotSelectAim = i;
					}

					if (isSelected) {
						ImGui::SetItemDefaultFocus();
					}
				}
				ImGui::EndCombo();
			}
		}
		ImGui::EndChild();
	}
}

void imGuiMenu::miscRender() {
	if (tabCount == 3) {
		ImGui::BeginChild("Movement", ImVec2(0, imGuiMenu::heightSeparatorInt), true);
		ImGui::PushFont(imGuiMenu::titleText);
		ImGui::Text("Movement");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Bunny hop", &miscConf.bunnyHop);
		ImGui::EndChild();

		horizontalSplitter(HEIGHT);

		ImGui::BeginChild("Visual", ImVec2(0, 0), true);
		ImGui::PushFont(imGuiMenu::titleText);
		ImGui::Text("Visual");
		ImGui::PopFont();
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Anti flash", &miscConf.flash);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Fov Changer", &miscConf.fovCheck);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		if (miscConf.fovCheck) {
			ImGui::SliderInt("FOV", &miscConf.fov, 30, 140);
			ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		}
		ImGui::Checkbox("DeathMatch Mode", &miscConf.deathmatchMode);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Dropped Item ESP", &miscConf.itemESP);
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		ImGui::Checkbox("Spectator List", &miscConf.spectator);
		ImGui::EndChild();
	}
}

void imGuiMenu::aboutMeRender() {
    if (tabCount == 4) {
        ImGui::BeginChild("About the project:", ImVec2(0, 0), true);

        ImGui::PushFont(imGuiMenu::titleText);
        ImGui::Text("Github");
        ImGui::PopFont();

        ImGui::Text("https://github.com/svxy/SCS2");
        ImGui::Text(" - Explore the project repo.");

        ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace * 2));

        ImGui::PushFont(imGuiMenu::subTitleText);
        ImGui::Text("Developer");
        ImGui::PopFont();

        ImGui::Text("https://github.com/svxy");
        ImGui::Text(" - Check out my GitHub profile.");

        ImGui::EndChild();
    }
}

void imGuiMenu::configRender() {
	if (tabCount == 5) {
		ImGui::BeginChild("Configuration File", ImVec2(0, 0), true);
		if (ImGui::Button("Save", ImVec2(55, 30))) {
			config::save();
		}
		ImGui::Dummy(ImVec2(0.0f, textSeparatorSpace));
		if (ImGui::Button("Load", ImVec2(55, 30))) {
			config::load();
		}
		ImGui::EndChild();
	}
}

void imGuiMenu::menuBar() {
	ImGui::BeginMenuBar();

	if (ImGui::MenuItem("ESP")) tabCount = 1;
	if (ImGui::MenuItem("Aim")) tabCount = 2;
	if (ImGui::MenuItem("Misc")) tabCount = 3;
	if (ImGui::MenuItem("About")) tabCount = 4;
	if (ImGui::MenuItem("Config")) tabCount = 5;

	ImGui::EndMenuBar();
}


void imGuiMenu::renderMenu(bool state) {
	ImGui::PushFont(normalText);
	ImGui::SetNextWindowSize({WIDTH,HEIGHT}, ImGuiCond_FirstUseEver);
	ImGui::Begin("SCS2", &state, ImGuiWindowFlags_MenuBar);
	
	// Config
	setStyle();
	menuBar();

	// Menus
	espRender();
	aimRender();
	miscRender();
	aboutMeRender();
	configRender();

	ImGui::PopFont();
	ImGui::End();
}