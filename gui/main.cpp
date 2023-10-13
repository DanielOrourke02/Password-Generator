#include "imgui\imgui.h"
#include "imgui\imgui_impl_win32.h"
#include "imgui\imgui_impl_dx9.h"
#include "funcs.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <d3d9.h>
#include <tchar.h>

const char alphanum[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int string_length = sizeof(alphanum) - 1;

std::string generatedPassword;
bool generatePasswordRequested = false;

std::string generatePassword(int l)
{
    std::string password;
    for (int i = 0; i < l; i++) // repeats the amount of times as the length of the password e.g 6 
    {
        password += alphanum[rand() % string_length];
    }
    return password;
}

void main_tabs()
{
    srand(static_cast<unsigned>(time(nullptr))); // seed random generation

    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoBackground;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    window_flags |= ImGuiWindowFlags_NoResize;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoNav;

    ImGui::Begin("Password Generator", NULL, window_flags);
    ImGui::SetNextWindowSizeConstraints(ImGui::GetMainViewport()->Size, ImGui::GetMainViewport()->Size);


    static int dpl = 6;
    ImGui::SliderInt("Password Length", &dpl, 6, 20); // slider for password length
    ImGui::Spacing();

    static std::string generatedPassword;
    const char* passwordCString = generatedPassword.c_str();

    ImGui::BeginChild("results");

    if (ImGui::Button("Generate"))
    {
        generatedPassword = generatePassword(dpl);
    }

    ImGui::Text("%s", passwordCString);
    ImGui::Spacing();
    
    if (ImGui::Button("Copy to clipboard"))
    {
        ImGui::SetClipboardText(passwordCString);
    }

    static char buf[32] = "";
    ImGui::InputText("UTF-8 input", buf, IM_ARRAYSIZE(buf));

    ImGui::EndChild();
    ImGui::End();
}
