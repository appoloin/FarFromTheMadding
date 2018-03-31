/*
 * mainWindow.h
 *
 *  Created on: 21 Oct 2016
 *      Author: andrew
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <gtkmm.h>
#include <thread>
#include <mutex>
#include "Game.h"
#include <vector>
#include <string>

class mainWindow : public Gtk::Window
{

	public:
	  mainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
	  virtual ~mainWindow();
	  void notify();

	protected:
	  //Signal handlers:
	  void on_btnStart_clicked();
	  void on_btnStop_clicked();
	  void on_btnQuit_clicked();
	  void on_btnBack_clicked();
	  void on_btnForward_clicked();
	  void on_notification_from_Game();

	  void update_widget();
	  void display_result(GameBoard);
	  void clear_result();
	  Glib::RefPtr<Gdk::Pixbuf> image_picker(int);

	  //Member widgets:
	  Glib::RefPtr<Gtk::Builder> m_Builder;
	  Gtk::Button *m_BtnStart, *m_BtnStop, *m_BtnForward, *m_BtnBack;
	  Gtk::Statusbar *m_StatusOne;
	  Gtk::Label *m_Label1,  *m_Label2, *m_Label3, *m_Label4, *m_Label5, *m_Label6, *m_Label7,*m_Label8,
	  	  	  	 *m_Label9,  *m_Label10, *m_Label11, *m_Label12, *m_Label13, *m_Label14, *m_Label15,*m_Label16,
				 *m_Label17,  *m_Label18, *m_Label19, *m_Label20, *m_Label21;
	  Gtk::Image *m_sq1image1, *m_sq1image2,*m_sq1image3,*m_sq1image4,*m_sq1image5,
	  	  	  	 *m_sq2image1, *m_sq2image2,*m_sq2image3,*m_sq2image4,*m_sq2image5,
				 *m_sq3image1, *m_sq3image2,*m_sq3image3,*m_sq3image4,*m_sq3image5,
				 *m_sq4image1, *m_sq4image2,*m_sq4image3,*m_sq4image4,*m_sq4image5,
				 *m_sq5image1, *m_sq5image2,*m_sq5image3,*m_sq5image4,*m_sq5image5,
				 *m_sq6image1, *m_sq6image2,*m_sq6image3,*m_sq6image4,*m_sq6image5,
				 *m_sq7image1, *m_sq7image2,*m_sq7image3,*m_sq7image4,*m_sq7image5,
				 *m_sq8image1, *m_sq8image2,*m_sq8image3,*m_sq8image4,*m_sq8image5,
				 *m_sq9image1, *m_sq9image2,*m_sq9image3,*m_sq9image4,*m_sq9image5,
				 *m_sq10image1, *m_sq10image2,*m_sq10image3,*m_sq10image4,*m_sq10image5,
				 *m_sq11image1, *m_sq11image2,*m_sq11image3,*m_sq11image4,*m_sq11image5,
				 *m_sq12image1, *m_sq12image2,*m_sq12image3,*m_sq12image4,*m_sq12image5,
				 *m_sq13image1, *m_sq13image2,*m_sq13image3,*m_sq13image4,*m_sq13image5,
				 *m_sq14image1, *m_sq14image2,*m_sq14image3,*m_sq14image4,*m_sq14image5,
				 *m_sq15image1, *m_sq15image2,*m_sq15image3,*m_sq15image4,*m_sq15image5,
				 *m_sq16image1, *m_sq16image2,*m_sq16image3,*m_sq16image4,*m_sq16image5,
				 *m_sq17image1, *m_sq17image2,*m_sq17image3,*m_sq17image4,*m_sq17image5,
				 *m_sq18image1, *m_sq18image2,*m_sq18image3,*m_sq18image4,*m_sq18image5,
				 *m_sq19image1, *m_sq19image2,*m_sq19image3,*m_sq19image4,*m_sq19image5,
				 *m_sq20image1, *m_sq20image2,*m_sq20image3,*m_sq20image4,*m_sq20image5,
				 *m_sq21image1, *m_sq21image2,*m_sq21image3,*m_sq21image4,*m_sq21image5;

	  Glib::RefPtr<Gdk::Pixbuf> imageRed;
	  Glib::RefPtr<Gdk::Pixbuf> imageBlue;
	  Glib::RefPtr<Gdk::Pixbuf> imageGreen;
	  Glib::RefPtr<Gdk::Pixbuf> imageWhite;

	  Game m_Game;
	  Glib::Dispatcher m_Dispatcher;
	  std::thread* m_WorkerThread;
	  int m_iDisplayCount;
};




#endif /* MAINWINDOW_H_ */
