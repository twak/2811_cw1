//
// Created by twak on 14/10/2019.
// DO NOT EDIT THIS FILE
//

#include "folder_compressor.h"
#include "screenshot.h"
#include <QApplication>
#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <QString>
#include<ctime>
#include <regex>
#include <errno.h>
#include <dirent.h> // this might be tricky, but mostly there for gnu compilers.

#if defined(_WIN32)
#include <direct.h>
#endif

//using namespace std;


inline bool exists(const std::string& name) {  // https://stackoverflow.com/questions/12774207
    std::ifstream f(name.c_str());
    return f.good();
}

void pack(const std::string& srcLocation) {
    std::string username;

    if (!exists(srcLocation+"/report/index.html")) {
        std::cout << "no report file generated. Run with 'test' before 'pack'." << std::endl;
        exit(-3);
    }

    std::string patchFile = srcLocation+"/../submit.patch";

    FolderCompressor fc(NULL);
    bool success = fc.compressFolder( QString(srcLocation.c_str()),
                                      QString ( patchFile.c_str() ) );

    if (!success)
        std::cout << "failed to write " << patchFile << std::endl;
    else
        std::cout << "please submit: " << patchFile << std::endl;
}

void mkdir_ ( std::string sPath) {  // https://stackoverflow.com/a/35109823/708802
    int nError = 0;
    #if defined(_WIN32)
      nError = _mkdir(sPath.c_str()); // can be used on Windows
    #else
      nError = mkdir(sPath.c_str(), S_IRWXU); // can be used on non-Windows
    #endif
    if (nError != 0) {
      std::cout << "error creating directory "<< sPath <<". quitting.";
      exit (-2);
    }
}

void unpack (const std::string& patchFile, const std::string& tmpFile) {
//    string patchFile = srcLocation+"/../submit.patch";
//    string tmpFile = srcLocation+"/../tmp_"+ to_string( std::time(0) )+"/";

    mkdir_ ( tmpFile.c_str() );

    FolderCompressor fc(NULL);
    bool success = fc.decompressFolder(QString ( patchFile.c_str() ), QString (tmpFile.c_str()) );

    if (!success)
        std::cout << "failed to unpack " << patchFile << std::endl;
    else
        std::cout << "files unpacked to: " << tmpFile << std::endl;
}

void unpackAll()
{
    // where are the student's patch files? (all in one directory from minerva).
    std::string dir = "C:\\Users\\twak\\Downloads\\gradebook_202122_34881_XJCO2811_CW23a20Responsive_2021-11-23-14-52-40";
    // where should the student's files be unpatched to?
    const std::string outdir = "C:\\Users\\twak\\Downloads\\swjtu_unpatch_cw2";

    const std::regex usrReg("Responsive\\_([0-9a-z]+)\\_attempt");

    if (auto submissionFolder = opendir(dir.c_str())) {
        while (auto f = readdir(submissionFolder)) {

            if (!f->d_name || f->d_name[0] == '.')
                continue;

            std::cout << f->d_name << std::endl;

            std::string name = std::string (f->d_name);

            std::string username = name;
            std::smatch m;

            if (regex_search(name, m, usrReg))
                username = m[1].str();

            std::string dirn = dir + "\\" + name;
            std::string username2 = username;
//            string outdir2 = outdir;

            std::cout << "*** starting unpatch " + username << std::endl;
            unpack( dirn, outdir + "\\" + username);
            std::cout << "*** finished unpatch " << username << std::endl;
         }
     }
    else
        printf("Oh dear, something went wrong %s\n", strerror(errno));

}


int main(int argc, char *argv[]) {

    unpack ("C:\\Users\\twak\\Downloads\\cw2_lates_submitted\\cw2_lates_submitted\\CW2_ Responsive_sc20nr_attempt_2021-11-17-15-48-06_submit.patch",
            "C:\\Users\\twak\\Downloads\\cw2_lates_submitted\\cw2_lates_submitted\\sc20nr");

    //unpackAll();

//    { // run interactively
//        // create the Qt Application
//        QApplication app(argc, argv);
//        // interactive mode - run the regular superclass
//        ResponsiveWindow window;
//        window.show();
//        // wait for the app to terminate
//        return app.exec();
//    }

    return 0;
}
