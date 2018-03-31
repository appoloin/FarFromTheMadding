/*
 * mainWindow.cpp
 *
 *  Created on: 21 Oct 2016
 *      Author: andrew
 */
#include "mainWindow.h"
#include <iostream>
#include <vector>
#include <string>

#ifndef NDEBUG
	#define DeBug(msg)  std::cout << msg << std::endl
#else
	#define DeBug(msg)
#endif



mainWindow::mainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
					   Gtk::Window(cobject),
					   m_Builder(refGlade),
					   m_WorkerThread(nullptr)
{
	m_Builder->get_widget("button1", m_BtnStart);
	m_Builder->get_widget("button2", m_BtnStop);
	m_Builder->get_widget("button4", m_BtnBack);
	m_Builder->get_widget("button3", m_BtnForward);

	m_Builder->get_widget("statusbar1",m_StatusOne);

	m_Builder->get_widget("label1",m_Label1);
	m_Builder->get_widget("label2",m_Label2);
	m_Builder->get_widget("label3",m_Label3);
	m_Builder->get_widget("label4",m_Label4);
	m_Builder->get_widget("label5",m_Label5);
	m_Builder->get_widget("label6",m_Label6);
	m_Builder->get_widget("label7",m_Label7);
	m_Builder->get_widget("label8",m_Label8);
	m_Builder->get_widget("label9",m_Label9);
	m_Builder->get_widget("label10",m_Label10);
	m_Builder->get_widget("label11",m_Label11);
	m_Builder->get_widget("label12",m_Label12);
	m_Builder->get_widget("label13",m_Label13);
	m_Builder->get_widget("label14",m_Label14);
	m_Builder->get_widget("label15",m_Label15);
	m_Builder->get_widget("label16",m_Label16);
	m_Builder->get_widget("label17",m_Label17);
	m_Builder->get_widget("label18",m_Label18);
	m_Builder->get_widget("label19",m_Label19);
	m_Builder->get_widget("label20",m_Label20);
	m_Builder->get_widget("label21",m_Label21);

	m_Builder->get_widget("sq1image1",m_sq1image1);
	m_Builder->get_widget("sq1image2",m_sq1image2);
	m_Builder->get_widget("sq1image3",m_sq1image3);
	m_Builder->get_widget("sq1image4",m_sq1image4);
	m_Builder->get_widget("sq1image5",m_sq1image5);
	m_Builder->get_widget("sq2image1",m_sq2image1);
	m_Builder->get_widget("sq2image2",m_sq2image2);
	m_Builder->get_widget("sq2image3",m_sq2image3);
	m_Builder->get_widget("sq2image4",m_sq2image4);
	m_Builder->get_widget("sq2image5",m_sq2image5);
	m_Builder->get_widget("sq3image1",m_sq3image1);
	m_Builder->get_widget("sq3image2",m_sq3image2);
	m_Builder->get_widget("sq3image3",m_sq3image3);
	m_Builder->get_widget("sq3image4",m_sq3image4);
	m_Builder->get_widget("sq3image5",m_sq3image5);
	m_Builder->get_widget("sq4image1",m_sq4image1);
	m_Builder->get_widget("sq4image2",m_sq4image2);
	m_Builder->get_widget("sq4image3",m_sq4image3);
	m_Builder->get_widget("sq4image4",m_sq4image4);
	m_Builder->get_widget("sq4image5",m_sq4image5);
	m_Builder->get_widget("sq5image1",m_sq5image1);
	m_Builder->get_widget("sq5image2",m_sq5image2);
	m_Builder->get_widget("sq5image3",m_sq5image3);
	m_Builder->get_widget("sq5image4",m_sq5image4);
	m_Builder->get_widget("sq5image5",m_sq5image5);
	m_Builder->get_widget("sq6image1",m_sq6image1);
	m_Builder->get_widget("sq6image2",m_sq6image2);
	m_Builder->get_widget("sq6image3",m_sq6image3);
	m_Builder->get_widget("sq6image4",m_sq6image4);
	m_Builder->get_widget("sq6image5",m_sq6image5);
	m_Builder->get_widget("sq7image1",m_sq7image1);
	m_Builder->get_widget("sq7image2",m_sq7image2);
	m_Builder->get_widget("sq7image3",m_sq7image3);
	m_Builder->get_widget("sq7image4",m_sq7image4);
	m_Builder->get_widget("sq7image5",m_sq7image5);
	m_Builder->get_widget("sq8image1",m_sq8image1);
	m_Builder->get_widget("sq8image2",m_sq8image2);
	m_Builder->get_widget("sq8image3",m_sq8image3);
	m_Builder->get_widget("sq8image4",m_sq8image4);
	m_Builder->get_widget("sq8image5",m_sq8image5);
	m_Builder->get_widget("sq9image1",m_sq9image1);
	m_Builder->get_widget("sq9image2",m_sq9image2);
	m_Builder->get_widget("sq9image3",m_sq9image3);
	m_Builder->get_widget("sq9image4",m_sq9image4);
	m_Builder->get_widget("sq9image5",m_sq9image5);
	m_Builder->get_widget("sq10image1",m_sq10image1);
	m_Builder->get_widget("sq10image2",m_sq10image2);
	m_Builder->get_widget("sq10image3",m_sq10image3);
	m_Builder->get_widget("sq10image4",m_sq10image4);
	m_Builder->get_widget("sq10image5",m_sq10image5);
	m_Builder->get_widget("sq11image1",m_sq11image1);
	m_Builder->get_widget("sq11image2",m_sq11image2);
	m_Builder->get_widget("sq11image3",m_sq11image3);
	m_Builder->get_widget("sq11image4",m_sq11image4);
	m_Builder->get_widget("sq11image5",m_sq11image5);
	m_Builder->get_widget("sq12image1",m_sq12image1);
	m_Builder->get_widget("sq12image2",m_sq12image2);
	m_Builder->get_widget("sq12image3",m_sq12image3);
	m_Builder->get_widget("sq12image4",m_sq12image4);
	m_Builder->get_widget("sq12image5",m_sq12image5);
	m_Builder->get_widget("sq13image1",m_sq13image1);
	m_Builder->get_widget("sq13image2",m_sq13image2);
	m_Builder->get_widget("sq13image3",m_sq13image3);
	m_Builder->get_widget("sq13image4",m_sq13image4);
	m_Builder->get_widget("sq13image5",m_sq13image5);
	m_Builder->get_widget("sq14image1",m_sq14image1);
	m_Builder->get_widget("sq14image2",m_sq14image2);
	m_Builder->get_widget("sq14image3",m_sq14image3);
	m_Builder->get_widget("sq14image4",m_sq14image4);
	m_Builder->get_widget("sq14image5",m_sq14image5);
	m_Builder->get_widget("sq15image1",m_sq15image1);
	m_Builder->get_widget("sq15image2",m_sq15image2);
	m_Builder->get_widget("sq15image3",m_sq15image3);
	m_Builder->get_widget("sq15image4",m_sq15image4);
	m_Builder->get_widget("sq15image5",m_sq15image5);
	m_Builder->get_widget("sq16image1",m_sq16image1);
	m_Builder->get_widget("sq16image2",m_sq16image2);
	m_Builder->get_widget("sq16image3",m_sq16image3);
	m_Builder->get_widget("sq16image4",m_sq16image4);
	m_Builder->get_widget("sq16image5",m_sq16image5);
	m_Builder->get_widget("sq17image1",m_sq17image1);
	m_Builder->get_widget("sq17image2",m_sq17image2);
	m_Builder->get_widget("sq17image3",m_sq17image3);
	m_Builder->get_widget("sq17image4",m_sq17image4);
	m_Builder->get_widget("sq17image5",m_sq17image5);
	m_Builder->get_widget("sq18image1",m_sq18image1);
	m_Builder->get_widget("sq18image2",m_sq18image2);
	m_Builder->get_widget("sq18image3",m_sq18image3);
	m_Builder->get_widget("sq18image4",m_sq18image4);
	m_Builder->get_widget("sq18image5",m_sq18image5);
	m_Builder->get_widget("sq19image1",m_sq19image1);
	m_Builder->get_widget("sq19image2",m_sq19image2);
	m_Builder->get_widget("sq19image3",m_sq19image3);
	m_Builder->get_widget("sq19image4",m_sq19image4);
	m_Builder->get_widget("sq19image5",m_sq19image5);
	m_Builder->get_widget("sq20image1",m_sq20image1);
	m_Builder->get_widget("sq20image2",m_sq20image2);
	m_Builder->get_widget("sq20image3",m_sq20image3);
	m_Builder->get_widget("sq20image4",m_sq20image4);
	m_Builder->get_widget("sq20image5",m_sq20image5);
	m_Builder->get_widget("sq21image1",m_sq21image1);
	m_Builder->get_widget("sq21image2",m_sq21image2);
	m_Builder->get_widget("sq21image3",m_sq21image3);
	m_Builder->get_widget("sq21image4",m_sq21image4);
	m_Builder->get_widget("sq21image5",m_sq21image5);


	// Connect the handler to the dispatcher.
	m_Dispatcher.connect(sigc::mem_fun(*this, &mainWindow::on_notification_from_Game));

	//Connect to GUI
	m_BtnStart->signal_clicked().connect(sigc::mem_fun(*this, &mainWindow::on_btnStart_clicked));
	m_BtnStop->signal_clicked().connect(sigc::mem_fun(*this, &mainWindow::on_btnStop_clicked));
	m_BtnStop->set_sensitive(false);
	m_BtnForward->signal_clicked().connect(sigc::mem_fun(*this, &mainWindow::on_btnForward_clicked));
	m_BtnForward->set_sensitive(false);
	m_BtnBack->signal_clicked().connect(sigc::mem_fun(*this, &mainWindow::on_btnBack_clicked));
	m_BtnBack->set_sensitive(false);

	imageRed = Gdk::Pixbuf::create_from_file("resources/redimage.svg");
	imageBlue = Gdk::Pixbuf::create_from_file("resources/blueimage.svg");;
	imageGreen = Gdk::Pixbuf::create_from_file("resources/greenimage.svg");
	imageWhite =  Gdk::Pixbuf::create_from_file("resources/whiteimage.svg");;

	m_iDisplayCount=0;

	m_sq1image1->clear();
	m_sq1image2->clear();
	m_sq1image3->clear();
	m_sq1image4->clear();
	m_sq1image5->clear();
	m_sq2image1->clear();
	m_sq2image2->clear();
	m_sq2image3->clear();
	m_sq2image4->clear();
	m_sq2image5->clear();
	m_sq3image1->clear();
	m_sq3image2->clear();
	m_sq3image3->clear();
	m_sq3image4->clear();
	m_sq3image5->clear();
	m_sq4image1->clear();
	m_sq4image2->clear();
	m_sq4image3->clear();
	m_sq4image4->clear();
	m_sq4image5->clear();
	m_sq5image1->clear();
	m_sq5image2->clear();
	m_sq5image3->clear();
	m_sq5image4->clear();
	m_sq5image5->clear();
	m_sq6image1->clear();
	m_sq6image2->clear();
	m_sq6image3->clear();
	m_sq6image4->clear();
	m_sq6image5->clear();
	m_sq7image1->clear();
	m_sq7image2->clear();
	m_sq7image3->clear();
	m_sq7image4->clear();
	m_sq7image5->clear();
	m_sq8image1->clear();
	m_sq8image2->clear();
	m_sq8image3->clear();
	m_sq8image4->clear();
	m_sq8image5->clear();
	m_sq9image1->clear();
	m_sq9image2->clear();
	m_sq9image3->clear();
	m_sq9image4->clear();
	m_sq9image5->clear();
	m_sq10image1->clear();
	m_sq10image2->clear();
	m_sq10image3->clear();
	m_sq10image4->clear();
	m_sq10image5->clear();
	m_sq11image1->clear();
	m_sq11image2->clear();
	m_sq11image3->clear();
	m_sq11image4->clear();
	m_sq11image5->clear();
	m_sq12image1->clear();
	m_sq12image2->clear();
	m_sq12image3->clear();
	m_sq12image4->clear();
	m_sq12image5->clear();
	m_sq13image1->clear();
	m_sq13image2->clear();
	m_sq13image3->clear();
	m_sq13image4->clear();
	m_sq13image5->clear();
	m_sq14image1->clear();
	m_sq14image2->clear();
	m_sq14image3->clear();
	m_sq14image4->clear();
	m_sq14image5->clear();
	m_sq15image1->clear();
	m_sq15image2->clear();
	m_sq15image3->clear();
	m_sq15image4->clear();
	m_sq15image5->clear();
	m_sq16image1->clear();
	m_sq16image2->clear();
	m_sq16image3->clear();
	m_sq16image4->clear();
	m_sq16image5->clear();
	m_sq17image1->clear();
	m_sq17image2->clear();
	m_sq17image3->clear();
	m_sq17image4->clear();
	m_sq17image5->clear();
	m_sq18image1->clear();
	m_sq18image2->clear();
	m_sq18image3->clear();
	m_sq18image4->clear();
	m_sq18image5->clear();
	m_sq19image1->clear();
	m_sq19image2->clear();
	m_sq19image3->clear();
	m_sq19image4->clear();
	m_sq19image5->clear();
	m_sq20image1->clear();
	m_sq20image2->clear();
	m_sq20image3->clear();
	m_sq20image4->clear();
	m_sq20image5->clear();
	m_sq21image1->clear();
	m_sq21image2->clear();
	m_sq21image3->clear();
	m_sq21image4->clear();
	m_sq21image5->clear();
}





mainWindow::~mainWindow()
{
	if (m_WorkerThread->joinable())
		m_WorkerThread->join();
	delete m_WorkerThread;
	m_WorkerThread = nullptr;
}



void mainWindow::on_btnStart_clicked()
{
	try
	{
		DeBug("on_btnStart_clicked - Start");

		m_BtnStop->set_sensitive(true);
		m_BtnStart->set_sensitive(false);
		m_BtnBack->set_sensitive(false);
		m_BtnForward->set_sensitive(false);
		clear_result();

		if (m_WorkerThread)
		{
			DeBug("on_btnStart_clicked - Thread Running");
			m_StatusOne->push("Can't start a worker thread while another one is running.");
		}
		else
		{
			DeBug("on_btnStart_clicked - Creating Thread");
			// Start a new worker thread.
			m_WorkerThread = new std::thread([this]
											  {
												m_Game.play_game(this);
											  });
			m_StatusOne->push("Started Thread");
		}

		DeBug("on_btnStart_clicked - End");
	}
	catch(const std::exception& e)
	{
		DeBug("on_btnStart_clicked - ERROR " << e.what());
	}
}





void mainWindow::on_btnStop_clicked()
{
	try
	{
		DeBug("on_btnStop_clicked - Start");
		if (!m_WorkerThread)
		{
			DeBug("on_btnStop_clicked - Thread Not Running");
			m_StatusOne->push("Can't stop a worker thread. None is running.");
		}
		else
		{
			DeBug("on_btnStop_clicked - Thread signaled  to stop");
			// Order the worker thread to stop.
			m_Game.stop_game();
			m_StatusOne->push("Stopping Thread");
			m_BtnStop->set_sensitive(false);
			m_BtnStart->set_sensitive(true);
		}
		DeBug("on_btnStop_clicked - End");
	}
	catch(const std::exception& e)
	{
		DeBug("on_btnStop_clicked - ERROR " << e.what());
	}
}



void mainWindow::on_btnBack_clicked()
{
	try
	{
		DeBug("on_btnBack_clicked - Start");

		int iNum =m_Game.get_result_num();
		if (iNum>0)
		{
			m_iDisplayCount--;
			DeBug("on_btnBack_clicked - m_iDisplayCount " << m_iDisplayCount << " iNum " << iNum);
			if ( m_iDisplayCount>=1 &&  m_iDisplayCount<=iNum)
				display_result(m_Game.get_result(m_iDisplayCount-1));//get next result
			else
			{
				m_iDisplayCount =iNum;
				display_result(m_Game.get_result(m_iDisplayCount-1));//get last result
			}

			m_StatusOne->push("Number of results "+std::to_string(iNum) +
							  "   Dispalying Number : " + std::to_string(m_iDisplayCount));
		}

		DeBug("on_btnBack_clicked - End");
	}
	catch(const std::exception& e)
	{
		DeBug("on_btnBack_clicked - ERROR " << e.what());
	}
}



void mainWindow::on_btnForward_clicked()
{
	try
	{
		DeBug("on_btnForward_clicked - Start");

		int iNum =m_Game.get_result_num();
		if (iNum>0)
		{
			m_iDisplayCount++;
			DeBug("on_btnForward_clicked - m_iDisplayCount " << m_iDisplayCount << " iNum " << iNum);
			if (m_iDisplayCount>=0 &&  m_iDisplayCount<=iNum)
				display_result(m_Game.get_result(m_iDisplayCount-1));//get next result
			else
			{
				m_iDisplayCount =1;
				display_result(m_Game.get_result(m_iDisplayCount-1));//get first result
			}

			m_StatusOne->push("Number of results "+std::to_string(iNum) +
							  "   Displaying Number : " + std::to_string(m_iDisplayCount));
		}

		DeBug("on_btnForward_clicked - End");
	}
	catch(const std::exception& e)
	{
		DeBug("on_btnForward_clicked - ERROR " << e.what());
	}
}



// notify() is called from ExampleWorker::do_work(). It is executed in the worker
// thread. It triggers a call to on_notification_from_worker_thread(), which is
// executed in the GUI thread.
void mainWindow::notify()
{
	DeBug("notify - Start");

	m_Dispatcher.emit();

	DeBug("notify - End");
}





void mainWindow::on_notification_from_Game()
{
	try
	{
		DeBug("on_notification_from_Game - Start");

		m_StatusOne->push("Something has happened in Game");

		if (m_WorkerThread && m_Game.has_stopped())
		{
			// Work is done.
			if (m_WorkerThread->joinable()) m_WorkerThread->join();
			delete m_WorkerThread;
			m_WorkerThread = nullptr;
		}

		update_widget();

		DeBug("on_notification_from_Game - End");
	}
	catch(const std::exception& e)
	{
		DeBug("on_notification_from_Game - ERROR " << e.what());
	}
}





void mainWindow::update_widget()
{
	try
	{
		DeBug("updateWidget - Start");

		if(m_Game.has_stopped()==true)
		{
			m_StatusOne->push("Stopping Thread");
			m_BtnStop->set_sensitive(false);
			m_BtnStart->set_sensitive(true);
		}

		int iPoss =m_Game.get_possible_results_num();
		m_StatusOne->push("Number of possible results " +std::to_string(iPoss));

		int iNum =m_Game.get_result_num();
		if (iNum>0)
		{
			DeBug("on_notification_from_Game - Getting Result Total " << iNum );

			if (iNum>1)
			{
				m_BtnBack->set_sensitive(true);
				m_BtnForward->set_sensitive(true);
			}

			m_iDisplayCount = 1;
			display_result(m_Game.get_result(m_iDisplayCount-1));//get first result
			m_StatusOne->push("Number of results "+std::to_string(iNum) +
										  "   Displaying Number : " + std::to_string(m_iDisplayCount));
		}

		DeBug("updateWidget - End");
	}
	catch(const std::exception& e)
	{
		DeBug("updateWidget - ERROR " << e.what());
	}
}





void mainWindow::display_result(GameBoard oBoard)
{
	try
	{
		DeBug("write_result - Start ");
		std::vector<std::string> vString = oBoard.get_game_result();
		m_Label1->set_label(vString[0]);
		m_Label2->set_label(vString[1]);
		m_Label3->set_label(vString[2]);
		m_Label4->set_label(vString[3]);
		m_Label5->set_label(vString[4]);
		m_Label6->set_label(vString[5]);
		m_Label7->set_label(vString[6]);
		m_Label8->set_label(vString[7]);
		m_Label9->set_label(vString[8]);
		m_Label10->set_label(vString[9]);
		m_Label11->set_label(vString[10]);
		m_Label12->set_label(vString[11]);
		m_Label13->set_label(vString[12]);
		m_Label14->set_label(vString[13]);
		m_Label15->set_label(vString[14]);
		m_Label16->set_label(vString[15]);
		m_Label17->set_label(vString[16]);
		m_Label18->set_label(vString[17]);
		m_Label19->set_label(vString[18]);
		m_Label20->set_label(vString[19]);
		m_Label21->set_label(vString[20]);

		std::vector<Piece> vSquares = oBoard.get_sqaures();

		m_sq1image1->set(image_picker(vSquares[0].get_top_right()));
		m_sq1image2->set(image_picker(vSquares[0].get_centre_right()));
		m_sq1image3->set(image_picker(vSquares[0].get_bottom()));
		m_sq1image4->set(image_picker(vSquares[0].get_centre_left()));
		m_sq1image5->set(image_picker(vSquares[0].get_top_left()));
		m_sq2image1->set(image_picker(vSquares[1].get_top_right()));
		m_sq2image2->set(image_picker(vSquares[1].get_centre_right()));
		m_sq2image3->set(image_picker(vSquares[1].get_bottom()));
		m_sq2image4->set(image_picker(vSquares[1].get_centre_left()));
		m_sq2image5->set(image_picker(vSquares[1].get_top_left()));
		m_sq3image1->set(image_picker(vSquares[2].get_top_right()));
		m_sq3image2->set(image_picker(vSquares[2].get_centre_right()));
		m_sq3image3->set(image_picker(vSquares[2].get_bottom()));
		m_sq3image4->set(image_picker(vSquares[2].get_centre_left()));
		m_sq3image5->set(image_picker(vSquares[2].get_top_left()));
		m_sq4image1->set(image_picker(vSquares[3].get_top_right()));
		m_sq4image2->set(image_picker(vSquares[3].get_centre_right()));
		m_sq4image3->set(image_picker(vSquares[3].get_bottom()));
		m_sq4image4->set(image_picker(vSquares[3].get_centre_left()));
		m_sq4image5->set(image_picker(vSquares[3].get_top_left()));
		m_sq5image1->set(image_picker(vSquares[4].get_top_right()));
		m_sq5image2->set(image_picker(vSquares[4].get_centre_right()));
		m_sq5image3->set(image_picker(vSquares[4].get_bottom()));
		m_sq5image4->set(image_picker(vSquares[4].get_centre_left()));
		m_sq5image5->set(image_picker(vSquares[4].get_top_left()));
		m_sq6image1->set(image_picker(vSquares[5].get_top_right()));
		m_sq6image2->set(image_picker(vSquares[5].get_centre_right()));
		m_sq6image3->set(image_picker(vSquares[5].get_bottom()));
		m_sq6image4->set(image_picker(vSquares[5].get_centre_left()));
		m_sq6image5->set(image_picker(vSquares[5].get_top_left()));
		m_sq7image1->set(image_picker(vSquares[6].get_top_right()));
		m_sq7image2->set(image_picker(vSquares[6].get_centre_right()));
		m_sq7image3->set(image_picker(vSquares[6].get_bottom()));
		m_sq7image4->set(image_picker(vSquares[6].get_centre_left()));
		m_sq7image5->set(image_picker(vSquares[6].get_top_left()));
		m_sq8image1->set(image_picker(vSquares[7].get_top_right()));
		m_sq8image2->set(image_picker(vSquares[7].get_centre_right()));
		m_sq8image3->set(image_picker(vSquares[7].get_bottom()));
		m_sq8image4->set(image_picker(vSquares[7].get_centre_left()));
		m_sq8image5->set(image_picker(vSquares[7].get_top_left()));
		m_sq9image1->set(image_picker(vSquares[8].get_top_right()));
		m_sq9image2->set(image_picker(vSquares[8].get_centre_right()));
		m_sq9image3->set(image_picker(vSquares[8].get_bottom()));
		m_sq9image4->set(image_picker(vSquares[8].get_centre_left()));
		m_sq9image5->set(image_picker(vSquares[8].get_top_left()));
		m_sq10image1->set(image_picker(vSquares[9].get_top_right()));
		m_sq10image2->set(image_picker(vSquares[9].get_centre_right()));
		m_sq10image3->set(image_picker(vSquares[9].get_bottom()));
		m_sq10image4->set(image_picker(vSquares[9].get_centre_left()));
		m_sq10image5->set(image_picker(vSquares[9].get_top_left()));
		m_sq11image1->set(image_picker(vSquares[10].get_top_right()));
		m_sq11image2->set(image_picker(vSquares[10].get_centre_right()));
		m_sq11image3->set(image_picker(vSquares[10].get_bottom()));
		m_sq11image4->set(image_picker(vSquares[10].get_centre_left()));
		m_sq11image5->set(image_picker(vSquares[10].get_top_left()));
		m_sq12image1->set(image_picker(vSquares[11].get_top_right()));
		m_sq12image2->set(image_picker(vSquares[11].get_centre_right()));
		m_sq12image3->set(image_picker(vSquares[11].get_bottom()));
		m_sq12image4->set(image_picker(vSquares[11].get_centre_left()));
		m_sq12image5->set(image_picker(vSquares[11].get_top_left()));
		m_sq13image1->set(image_picker(vSquares[12].get_top_right()));
		m_sq13image2->set(image_picker(vSquares[12].get_centre_right()));
		m_sq13image3->set(image_picker(vSquares[12].get_bottom()));
		m_sq13image4->set(image_picker(vSquares[12].get_centre_left()));
		m_sq13image5->set(image_picker(vSquares[12].get_top_left()));
		m_sq14image1->set(image_picker(vSquares[13].get_top_right()));
		m_sq14image2->set(image_picker(vSquares[13].get_centre_right()));
		m_sq14image3->set(image_picker(vSquares[13].get_bottom()));
		m_sq14image4->set(image_picker(vSquares[13].get_centre_left()));
		m_sq14image5->set(image_picker(vSquares[13].get_top_left()));
		m_sq15image1->set(image_picker(vSquares[14].get_top_right()));
		m_sq15image2->set(image_picker(vSquares[14].get_centre_right()));
		m_sq15image3->set(image_picker(vSquares[14].get_bottom()));
		m_sq15image4->set(image_picker(vSquares[14].get_centre_left()));
		m_sq15image5->set(image_picker(vSquares[14].get_top_left()));
		m_sq16image1->set(image_picker(vSquares[15].get_top_right()));
		m_sq16image2->set(image_picker(vSquares[15].get_centre_right()));
		m_sq16image3->set(image_picker(vSquares[15].get_bottom()));
		m_sq16image4->set(image_picker(vSquares[15].get_centre_left()));
		m_sq16image5->set(image_picker(vSquares[15].get_top_left()));
		m_sq17image1->set(image_picker(vSquares[16].get_top_right()));
		m_sq17image2->set(image_picker(vSquares[16].get_centre_right()));
		m_sq17image3->set(image_picker(vSquares[16].get_bottom()));
		m_sq17image4->set(image_picker(vSquares[16].get_centre_left()));
		m_sq17image5->set(image_picker(vSquares[16].get_top_left()));
		m_sq18image1->set(image_picker(vSquares[17].get_top_right()));
		m_sq18image2->set(image_picker(vSquares[17].get_centre_right()));
		m_sq18image3->set(image_picker(vSquares[17].get_bottom()));
		m_sq18image4->set(image_picker(vSquares[17].get_centre_left()));
		m_sq18image5->set(image_picker(vSquares[17].get_top_left()));
		m_sq19image1->set(image_picker(vSquares[18].get_top_right()));
		m_sq19image2->set(image_picker(vSquares[18].get_centre_right()));
		m_sq19image3->set(image_picker(vSquares[18].get_bottom()));
		m_sq19image4->set(image_picker(vSquares[18].get_centre_left()));
		m_sq19image5->set(image_picker(vSquares[18].get_top_left()));
		m_sq20image1->set(image_picker(vSquares[19].get_top_right()));
		m_sq20image2->set(image_picker(vSquares[19].get_centre_right()));
		m_sq20image3->set(image_picker(vSquares[19].get_bottom()));
		m_sq20image4->set(image_picker(vSquares[19].get_centre_left()));
		m_sq20image5->set(image_picker(vSquares[19].get_top_left()));
		m_sq21image1->set(image_picker(vSquares[20].get_top_right()));
		m_sq21image2->set(image_picker(vSquares[20].get_centre_right()));
		m_sq21image3->set(image_picker(vSquares[20].get_bottom()));
		m_sq21image4->set(image_picker(vSquares[20].get_centre_left()));
		m_sq21image5->set(image_picker(vSquares[20].get_top_left()));

		DeBug("write_result - END ");
	}
	catch(const std::exception& e)
	{
		DeBug("write_result - ERROR " << e.what());
	}
}





void mainWindow::clear_result()
{
	try
	{
		DeBug("clear_result - Start ");

		m_Label1->set_label("");
		m_Label2->set_label("");
		m_Label3->set_label("");
		m_Label4->set_label("");
		m_Label5->set_label("");
		m_Label6->set_label("");
		m_Label7->set_label("");
		m_Label8->set_label("");
		m_Label9->set_label("");
		m_Label10->set_label("");
		m_Label11->set_label("");
		m_Label12->set_label("");
		m_Label13->set_label("");
		m_Label14->set_label("");
		m_Label15->set_label("");
		m_Label16->set_label("");
		m_Label17->set_label("");
		m_Label18->set_label("");
		m_Label19->set_label("");
		m_Label20->set_label("");
		m_Label21->set_label("");

		m_sq1image1->clear();
		m_sq1image2->clear();
		m_sq1image3->clear();
		m_sq1image4->clear();
		m_sq1image5->clear();
		m_sq2image1->clear();
		m_sq2image2->clear();
		m_sq2image3->clear();
		m_sq2image4->clear();
		m_sq2image5->clear();
		m_sq3image1->clear();
		m_sq3image2->clear();
		m_sq3image3->clear();
		m_sq3image4->clear();
		m_sq3image5->clear();
		m_sq4image1->clear();
		m_sq4image2->clear();
		m_sq4image3->clear();
		m_sq4image4->clear();
		m_sq4image5->clear();
		m_sq5image1->clear();
		m_sq5image2->clear();
		m_sq5image3->clear();
		m_sq5image4->clear();
		m_sq5image5->clear();
		m_sq6image1->clear();
		m_sq6image2->clear();
		m_sq6image3->clear();
		m_sq6image4->clear();
		m_sq6image5->clear();
		m_sq7image1->clear();
		m_sq7image2->clear();
		m_sq7image3->clear();
		m_sq7image4->clear();
		m_sq7image5->clear();
		m_sq8image1->clear();
		m_sq8image2->clear();
		m_sq8image3->clear();
		m_sq8image4->clear();
		m_sq8image5->clear();
		m_sq9image1->clear();
		m_sq9image2->clear();
		m_sq9image3->clear();
		m_sq9image4->clear();
		m_sq9image5->clear();
		m_sq10image1->clear();
		m_sq10image2->clear();
		m_sq10image3->clear();
		m_sq10image4->clear();
		m_sq10image5->clear();
		m_sq11image1->clear();
		m_sq11image2->clear();
		m_sq11image3->clear();
		m_sq11image4->clear();
		m_sq11image5->clear();
		m_sq12image1->clear();
		m_sq12image2->clear();
		m_sq12image3->clear();
		m_sq12image4->clear();
		m_sq12image5->clear();
		m_sq13image1->clear();
		m_sq13image2->clear();
		m_sq13image3->clear();
		m_sq13image4->clear();
		m_sq13image5->clear();
		m_sq14image1->clear();
		m_sq14image2->clear();
		m_sq14image3->clear();
		m_sq14image4->clear();
		m_sq14image5->clear();
		m_sq15image1->clear();
		m_sq15image2->clear();
		m_sq15image3->clear();
		m_sq15image4->clear();
		m_sq15image5->clear();
		m_sq16image1->clear();
		m_sq16image2->clear();
		m_sq16image3->clear();
		m_sq16image4->clear();
		m_sq16image5->clear();
		m_sq17image1->clear();
		m_sq17image2->clear();
		m_sq17image3->clear();
		m_sq17image4->clear();
		m_sq17image5->clear();
		m_sq18image1->clear();
		m_sq18image2->clear();
		m_sq18image3->clear();
		m_sq18image4->clear();
		m_sq18image5->clear();
		m_sq19image1->clear();
		m_sq19image2->clear();
		m_sq19image3->clear();
		m_sq19image4->clear();
		m_sq19image5->clear();
		m_sq20image1->clear();
		m_sq20image2->clear();
		m_sq20image3->clear();
		m_sq20image4->clear();
		m_sq20image5->clear();
		m_sq21image1->clear();
		m_sq21image2->clear();
		m_sq21image3->clear();
		m_sq21image4->clear();
		m_sq21image5->clear();
		DeBug("clear_result - END ");
	}
	catch(const std::exception& e)
	{
		DeBug("clear_result - ERROR " << e.what());
	}
}




Glib::RefPtr<Gdk::Pixbuf> mainWindow::image_picker(int iColour)
{
	try
	{
		Glib::RefPtr<Gdk::Pixbuf> temp;
		if (iColour == Piece::Red) temp = imageRed;
		else if (iColour == Piece::Blue)temp = imageBlue;
		else if (iColour == Piece::Green)temp = imageGreen;
		else if (iColour == Piece::Blank)temp = imageWhite;
		return temp;
	}
	catch(const std::exception& e)
	{
		DeBug("image_picker - ERROR " << e.what());
		return imageWhite;
	}
}






