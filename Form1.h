#pragma once
#include "People.h"

namespace snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 ���K�n
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button_start;
	protected: 

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(21, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(750, 697);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button_start
			// 
			this->button_start->Location = System::Drawing::Point(799, 499);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(131, 68);
			this->button_start->TabIndex = 1;
			this->button_start->Text = L"START";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &Form1::button_start_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1013, 843);
			this->Controls->Add(this->button_start);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		Graphics^ graph;
		People *people;
		Food *food;
		bool game_start;         //�}�l�C��
		bool food_eat;           //Ĳ�I
		int flag, fx, fy;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 graph = pictureBox1->CreateGraphics();
				 graph->Clear(Color::White);
				 people = new People();
				 food = new Food();
				 game_start = false;
				 food_eat = false;
				 fx = 0;
				 fy = 0;
				 CheckForIllegalCrossThreadCalls = false;
			 }

	private: System::Void button_start_Click(System::Object^  sender, System::EventArgs^  e) {
				 people->x = FIELD_WIDTH/2;
				 people->y = FIELD_HEIGHT/2;
				 button_start->Enabled = false;
				 game_start = true;
				 food->x = fx;
				 food->y = fy;
				 backgroundWorker1->RunWorkerAsync();
			 }

	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				while(true)
				{

					switch(flag)
					{
					case 37:	//����
						 if (people->x >PICTURE_WIDTH)
						 {
							 people-> x-=PICTURE_WIDTH;
						 }
						 else if (people->x < 0)
						 {
						 }
						 break;

					 case 38 :  //���W                    
						 if (people->y >PICTURE_HEIGHT)
						 {
							 people-> y-=PICTURE_HEIGHT;
						 }
						 break;

					 case 39:	//���k
						 if (people->x < FIELD_WIDTH-PICTURE_WIDTH)
						 {
							 people->x +=PICTURE_WIDTH;
						 }
						 break;
					 case 40:	//���U
						 if (people->y < FIELD_HEIGHT-PICTURE_HEIGHT)
						 {
							 people->y +=PICTURE_HEIGHT;
						 }
						 break;
					 }
			 
			 graph->Clear(Color::White);
			 people->draw(graph);
			 food->draw(graph);
			 System::Threading::Thread::Sleep(100);
			 }
		 }
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 switch (e->KeyValue)                
				 {
				 case 37 :  //������                    
					 flag = 37 ;
					 break;
				 case 38 :  //���k��
					 flag = 38;
					 break;
				 case 39 :  //���W                    
					 flag = 39;
					 break;
				 case 40 :  //���U
					 flag = 40;
					 break;
				 }
			 }
};
}

