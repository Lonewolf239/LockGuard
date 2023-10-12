#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <msclr/marshal_cppstd.h>

char* userProfile1;
size_t envSize1;
errno_t err = _dupenv_s(&userProfile1, &envSize1, "USERPROFILE");
std::string filePath1 = std::string(userProfile1) + "\\AppData\\Local\\LockGuar\\LockGuard_password.ini";
std::string Path1 = std::string(userProfile1) + "\\AppData\\Local\\LockGuar\\";

bool check() {
	std::ofstream mig(Path1 + "test.txt");
	if (mig.is_open()) {
		mig.close();
		std::string del = Path1 + "test.txt";
		remove(del.c_str());
		return true;
	}
	else
		return false;
}

namespace LockGuard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ get_pas_form
	/// </summary>
	public ref class get_pas_form : public System::Windows::Forms::Form
	{
	public:
		get_pas_form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~get_pas_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ cancel_btn;
	protected: System::ComponentModel::ComponentResourceManager^ resources1;
	private: System::Windows::Forms::TextBox^ pas_text;
	private: System::Windows::Forms::Button^ ok_btn;
	private: System::Windows::Forms::Label^ pas_label;
	private: System::Windows::Forms::PictureBox^ show_hide_pas;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(get_pas_form::typeid));
			this->cancel_btn = (gcnew System::Windows::Forms::Button());
			this->pas_text = (gcnew System::Windows::Forms::TextBox());
			this->ok_btn = (gcnew System::Windows::Forms::Button());
			this->pas_label = (gcnew System::Windows::Forms::Label());
			this->show_hide_pas = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->show_hide_pas))->BeginInit();
			this->SuspendLayout();
			// 
			// cancel_btn
			// 
			this->cancel_btn->BackColor = System::Drawing::Color::Transparent;
			this->cancel_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->cancel_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cancel_btn->ForeColor = System::Drawing::Color::White;
			this->cancel_btn->Location = System::Drawing::Point(182, 54);
			this->cancel_btn->Name = L"cancel_btn";
			this->cancel_btn->Size = System::Drawing::Size(90, 30);
			this->cancel_btn->TabIndex = 0;
			this->cancel_btn->TabStop = false;
			this->cancel_btn->Text = L"ќтмена";
			this->cancel_btn->UseVisualStyleBackColor = false;
			this->cancel_btn->Click += gcnew System::EventHandler(this, &get_pas_form::cancel_btn_Click);
			// 
			// pas_text
			// 
			this->pas_text->Location = System::Drawing::Point(9, 28);
			this->pas_text->Name = L"pas_text";
			this->pas_text->Size = System::Drawing::Size(235, 20);
			this->pas_text->TabIndex = 1;
			this->pas_text->UseSystemPasswordChar = true;
			this->pas_text->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &get_pas_form::pas_text_KeyPress);
			this->pas_text->MouseHover += gcnew System::EventHandler(this, &get_pas_form::pas_text_MouseHover);
			// 
			// ok_btn
			// 
			this->ok_btn->BackColor = System::Drawing::Color::Transparent;
			this->ok_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ok_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ok_btn->ForeColor = System::Drawing::Color::White;
			this->ok_btn->Location = System::Drawing::Point(86, 54);
			this->ok_btn->Name = L"ok_btn";
			this->ok_btn->Size = System::Drawing::Size(90, 30);
			this->ok_btn->TabIndex = 2;
			this->ok_btn->TabStop = false;
			this->ok_btn->Text = L"Ok";
			this->ok_btn->UseVisualStyleBackColor = false;
			this->ok_btn->Click += gcnew System::EventHandler(this, &get_pas_form::ok_btn_Click);
			// 
			// pas_label
			// 
			this->pas_label->AutoSize = true;
			this->pas_label->BackColor = System::Drawing::Color::Transparent;
			this->pas_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pas_label->ForeColor = System::Drawing::Color::White;
			this->pas_label->Location = System::Drawing::Point(5, 5);
			this->pas_label->Name = L"pas_label";
			this->pas_label->Size = System::Drawing::Size(139, 20);
			this->pas_label->TabIndex = 3;
			this->pas_label->Text = L"¬ведите пароль:";
			this->pas_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// show_hide_pas
			// 
			this->show_hide_pas->BackColor = System::Drawing::Color::Transparent;
			this->show_hide_pas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"show_hide_pas.Image")));
			this->show_hide_pas->Location = System::Drawing::Point(252, 28);
			this->show_hide_pas->Name = L"show_hide_pas";
			this->show_hide_pas->Size = System::Drawing::Size(20, 20);
			this->show_hide_pas->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->show_hide_pas->TabIndex = 4;
			this->show_hide_pas->TabStop = false;
			this->show_hide_pas->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &get_pas_form::show_hide_pas_MouseClick);
			// 
			// get_pas_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(284, 96);
			this->Controls->Add(this->show_hide_pas);
			this->Controls->Add(this->pas_label);
			this->Controls->Add(this->ok_btn);
			this->Controls->Add(this->pas_text);
			this->Controls->Add(this->cancel_btn);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"get_pas_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Lock Guard v1.0 Ч ¬вод парол€";
			this->TopMost = true;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &get_pas_form::get_pas_form_FormClosing);
			this->Load += gcnew System::EventHandler(this, &get_pas_form::get_pas_form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->show_hide_pas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cancel_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void ok_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->pas_text->Text->Length >= 8) {
			if (!check()) {
				std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
				std::wstring widePath = converter.from_bytes(Path1);
				CreateDirectoryW(widePath.c_str(), NULL);
			}
			std::ofstream did_pas(filePath1);
			if (did_pas.is_open()) {
				std::string password = msclr::interop::marshal_as<std::string>(this->pas_text->Text);
				did_pas << "[DATA]\npassword=" << password << "\nlocked=0\n";
				did_pas.close();
				Application::Exit();
			}
		}
		else
			MessageBox::Show("ѕароль должен содержать не менее 8 символов!", "Lock Guar Ч ¬нимание!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	private: System::Void get_pas_form_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Application::Exit();
	}
	private: System::Void show_hide_pas_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
			this->pas_text->UseSystemPasswordChar = !this->pas_text->UseSystemPasswordChar;
		if (this->pas_text->UseSystemPasswordChar)
			this->show_hide_pas->Image = (cli::safe_cast<System::Drawing::Image^>(resources1->GetObject(L"show_hide_pas.Image")));
		else
			this->show_hide_pas->Image = (cli::safe_cast<System::Drawing::Image^>(resources1->GetObject(L"show")));

	}
	private: System::Void get_pas_form_Load(System::Object^ sender, System::EventArgs^ e) {
		this->BringToFront();
		resources1 = (gcnew System::ComponentModel::ComponentResourceManager(get_pas_form::typeid));
	}
	private: System::Void pas_text_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar)) {
			if (e->KeyChar != 8 && e->KeyChar != 127)
				e->Handled = true;
		}
	}
	private: System::Void pas_text_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		ToolTip^ tooltip = gcnew ToolTip();
		tooltip->ToolTipIcon = ToolTipIcon::Info;
		tooltip->ToolTipTitle = "ѕодсказка";
		tooltip->SetToolTip(pas_text, "¬ведите только цифры");
	}
};
}