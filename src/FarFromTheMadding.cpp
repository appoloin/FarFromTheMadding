//============================================================================
// Name        : SomethingLikeThat.cpp
// Author      : 
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <gtkmm.h>
#include "mainWindow.h"

using namespace std;

int main(int argc, char *argv[])
{
	// Initialize gtkmm
	Glib::RefPtr<Gtk::Application>  app = Gtk::Application::create(argc, argv);
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("resources/GUI.glade");

	// Create the window
	mainWindow *oWindowMain;

	// Start main loop
	builder->get_widget_derived("windowMain", oWindowMain);
	app->run(*oWindowMain);
	delete oWindowMain;

	return 0;
}
