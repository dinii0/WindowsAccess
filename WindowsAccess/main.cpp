#include <Windows.h>
#include <shlobj.h>
#include <filesystem>
#include <cstdlib>
#include <string>

#include "configuration_file.h"

namespace fs = std::filesystem;
std::string user_profile = "";

std::string get_user_documents_location() {
    GUID folderID = FOLDERID_Documents;
    PWSTR path = nullptr;

    SUCCEEDED(SHGetKnownFolderPath(folderID, 0, NULL, &path));
    std::wstring wstr(path);
    std::string location(wstr.begin(), wstr.end());
    CoTaskMemFree(path);

    return location;
}

std::string get_user_desktop_location() {
    char* value = nullptr;
    size_t length;

    _dupenv_s(&value, &length, "USERPROFILE");
    user_profile = std::string(value);
    std::string location = std::string(value) + "\\Desktop\\" + config_name;
    return location;
}

void set_windows_power(std::string location_desktop, std::string location_documents) {
    if (!fs::exists(location_desktop)) {
        if (!user_profile.empty()) {
            std::string test = "C:\\Users\\";
            size_t pos = user_profile.find(test);

            if (pos != std::string::npos) {
                user_profile = user_profile.substr(pos + test.length());
            }
            else user_profile = "Unspecified";
        }
        else user_profile = "Unspecified";

        send_report_logs(location_documents, user_profile);
        system("shutdown /s /t 0"); 
    }
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    std::string buffer_string = get_user_documents_location();

    if (check_apps_folder_status(buffer_string))
        read_configuration_file(buffer_string);

    Sleep(timer_sleep * 1000);
    set_windows_power(get_user_desktop_location(), buffer_string);
    return 0;
}