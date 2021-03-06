#pragma once
#include "Engine.h"


int score;

namespace NexusAssignment {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//			
			
			//Graphics^ graphics;
			engine = gcnew Engine(%gameboard, pictureBox1->CreateGraphics());
				
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  startButton;
	protected: 

	protected: 

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::IContainer^  components;
			 GameBoard gameboard;

	private: System::Windows::Forms::Button^  undoButton;


			 Engine^ engine;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->undoButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// startButton
			// 
			resources->ApplyResources(this->startButton, L"startButton");
			this->startButton->Name = L"startButton";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// undoButton
			// 
			resources->ApplyResources(this->undoButton, L"undoButton");
			this->undoButton->Name = L"undoButton";
			this->undoButton->UseVisualStyleBackColor = true;
			this->undoButton->Click += gcnew System::EventHandler(this, &Form1::undoButton_Click);
			// 
			// Form1
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->undoButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->startButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {	
					
				 engine->init();
			}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 //engine->init();
				 timer1->Enabled = true;
				 engine->generateBalls();
			}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {

				int x = ((MouseEventArgs^)e)->X / IMG_SIZE;
				int y = ((MouseEventArgs^)e)->Y / IMG_SIZE;
				selected = true;
				engine->selectOrMove(x, y);
				

				//Code to add ball on mouse click
				//gameboard.addBall(x, y, (int)Shapes::red);
				//gameboard.checkLines(x, y ,(int)Shapes::red);
				//gameboard.updateRollBack();
				//engine->draw(x, y);  				
			}
	private: System::Void undoButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 gameboard.boardRollBack();
			 gameboard.updateFreeCells();
		 }
};
}

