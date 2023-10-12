#pragma once
#include <Windows.h>
#include "get_pas_form.h"
#include "ini/INIReader.h"
#include <locale>
#include <codecvt>
#pragma comment(lib, "Advapi32")
#pragma comment(lib, "user32.lib")

char* userProfile;
size_t envSize;
errno_t err1 = _dupenv_s(&userProfile, &envSize, "USERPROFILE");
std::string filePath = std::string(userProfile) + "\\AppData\\Local\\LockGuar\\LockGuard_password.ini";
std::string Path = std::string(userProfile) + "\\AppData\\Local\\LockGuar";
std::string password;
bool locked = false;
HHOOK keyboardHook = NULL;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HC_ACTION) {
		KBDLLHOOKSTRUCT* pKeyboardStruct = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
		if (wParam == WM_KEYDOWN || wParam == WM_KEYUP) {
			return 1;
		}
	}

	return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}
void SetKeyboardHook() {
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
}
void UnhookKeyboardHook() {
	UnhookWindowsHookEx(keyboardHook);
	keyboardHook = NULL;
	keybd_event(VK_LWIN, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
}


namespace LockGuard {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::TextBox^ pas_text;

	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Button^ relock_btn;
	private: System::Windows::Forms::Panel^ interface_panel;
	private: System::ComponentModel::ComponentResourceManager^ resources1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btn5;
	private: System::Windows::Forms::Button^ btn8;
	private: System::Windows::Forms::Button^ btn9;
	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::Button^ btn6;
	private: System::Windows::Forms::Button^ btn7;
	private: System::Windows::Forms::Button^ btn0;
	private: System::Windows::Forms::Button^ clear_last_btn;
	private: System::Windows::Forms::Button^ clear_btn;
	private: System::Windows::Forms::Label^ num_symbol;
	private: System::Windows::Forms::Label^ label1;



	private: bool now_closing = false;
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			this->interface_panel = (gcnew System::Windows::Forms::Panel());
			this->num_symbol = (gcnew System::Windows::Forms::Label());
			this->clear_btn = (gcnew System::Windows::Forms::Button());
			this->clear_last_btn = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->relock_btn = (gcnew System::Windows::Forms::Button());
			this->pas_text = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->interface_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// interface_panel
			// 
			this->interface_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->interface_panel->BackColor = System::Drawing::Color::Transparent;
			this->interface_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->interface_panel->Controls->Add(this->label1);
			this->interface_panel->Controls->Add(this->num_symbol);
			this->interface_panel->Controls->Add(this->clear_btn);
			this->interface_panel->Controls->Add(this->clear_last_btn);
			this->interface_panel->Controls->Add(this->btn5);
			this->interface_panel->Controls->Add(this->btn8);
			this->interface_panel->Controls->Add(this->btn7);
			this->interface_panel->Controls->Add(this->btn6);
			this->interface_panel->Controls->Add(this->btn9);
			this->interface_panel->Controls->Add(this->btn0);
			this->interface_panel->Controls->Add(this->btn4);
			this->interface_panel->Controls->Add(this->btn3);
			this->interface_panel->Controls->Add(this->btn2);
			this->interface_panel->Controls->Add(this->btn1);
			this->interface_panel->Controls->Add(this->relock_btn);
			this->interface_panel->Controls->Add(this->pas_text);
			this->interface_panel->Controls->Add(this->label);
			this->interface_panel->Location = System::Drawing::Point(0, 0);
			this->interface_panel->Name = L"interface_panel";
			this->interface_panel->Size = System::Drawing::Size(666, 480);
			this->interface_panel->TabIndex = 0;
			this->interface_panel->Visible = false;
			this->interface_panel->VisibleChanged += gcnew System::EventHandler(this, &main::interface_panel_VisibleChanged);
			// 
			// num_symbol
			// 
			this->num_symbol->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->num_symbol->AutoSize = true;
			this->num_symbol->BackColor = System::Drawing::Color::Transparent;
			this->num_symbol->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->num_symbol->ForeColor = System::Drawing::Color::White;
			this->num_symbol->Location = System::Drawing::Point(195, 115);
			this->num_symbol->Name = L"num_symbol";
			this->num_symbol->Size = System::Drawing::Size(106, 13);
			this->num_symbol->TabIndex = 15;
			this->num_symbol->Text = L"Кол-во символов: 0";
			this->num_symbol->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// clear_btn
			// 
			this->clear_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->clear_btn->BackColor = System::Drawing::Color::Transparent;
			this->clear_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->clear_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clear_btn->ForeColor = System::Drawing::Color::White;
			this->clear_btn->Location = System::Drawing::Point(196, 306);
			this->clear_btn->Name = L"clear_btn";
			this->clear_btn->Size = System::Drawing::Size(162, 50);
			this->clear_btn->TabIndex = 14;
			this->clear_btn->TabStop = false;
			this->clear_btn->Text = L"Стереть всё";
			this->clear_btn->UseVisualStyleBackColor = false;
			this->clear_btn->Click += gcnew System::EventHandler(this, &main::clear_btn_Click);
			// 
			// clear_last_btn
			// 
			this->clear_last_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->clear_last_btn->BackColor = System::Drawing::Color::Transparent;
			this->clear_last_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->clear_last_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clear_last_btn->ForeColor = System::Drawing::Color::White;
			this->clear_last_btn->Location = System::Drawing::Point(364, 306);
			this->clear_last_btn->Name = L"clear_last_btn";
			this->clear_last_btn->Size = System::Drawing::Size(50, 50);
			this->clear_last_btn->TabIndex = 13;
			this->clear_last_btn->TabStop = false;
			this->clear_last_btn->Text = L"⌫";
			this->clear_last_btn->UseVisualStyleBackColor = false;
			this->clear_last_btn->Click += gcnew System::EventHandler(this, &main::clear_last_btn_Click);
			// 
			// btn5
			// 
			this->btn5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn5->ForeColor = System::Drawing::Color::White;
			this->btn5->Location = System::Drawing::Point(420, 194);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(50, 50);
			this->btn5->TabIndex = 5;
			this->btn5->TabStop = false;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn8
			// 
			this->btn8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn8->ForeColor = System::Drawing::Color::White;
			this->btn8->Location = System::Drawing::Point(308, 250);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(50, 50);
			this->btn8->TabIndex = 8;
			this->btn8->TabStop = false;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn7
			// 
			this->btn7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn7->ForeColor = System::Drawing::Color::White;
			this->btn7->Location = System::Drawing::Point(252, 250);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(50, 50);
			this->btn7->TabIndex = 7;
			this->btn7->TabStop = false;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn6
			// 
			this->btn6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn6->ForeColor = System::Drawing::Color::White;
			this->btn6->Location = System::Drawing::Point(196, 250);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(50, 50);
			this->btn6->TabIndex = 6;
			this->btn6->TabStop = false;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn9
			// 
			this->btn9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn9->ForeColor = System::Drawing::Color::White;
			this->btn9->Location = System::Drawing::Point(364, 250);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(50, 50);
			this->btn9->TabIndex = 9;
			this->btn9->TabStop = false;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn0
			// 
			this->btn0->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn0->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn0->ForeColor = System::Drawing::Color::White;
			this->btn0->Location = System::Drawing::Point(420, 250);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(50, 50);
			this->btn0->TabIndex = 0;
			this->btn0->TabStop = false;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn4
			// 
			this->btn4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn4->ForeColor = System::Drawing::Color::White;
			this->btn4->Location = System::Drawing::Point(364, 194);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(50, 50);
			this->btn4->TabIndex = 4;
			this->btn4->TabStop = false;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn3
			// 
			this->btn3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn3->ForeColor = System::Drawing::Color::White;
			this->btn3->Location = System::Drawing::Point(308, 194);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(50, 50);
			this->btn3->TabIndex = 3;
			this->btn3->TabStop = false;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn2
			// 
			this->btn2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn2->ForeColor = System::Drawing::Color::White;
			this->btn2->Location = System::Drawing::Point(252, 194);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(50, 50);
			this->btn2->TabIndex = 2;
			this->btn2->TabStop = false;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// btn1
			// 
			this->btn1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn1->ForeColor = System::Drawing::Color::White;
			this->btn1->Location = System::Drawing::Point(196, 194);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(50, 50);
			this->btn1->TabIndex = 1;
			this->btn1->TabStop = false;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &main::num_btn_Click);
			// 
			// relock_btn
			// 
			this->relock_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->relock_btn->BackColor = System::Drawing::Color::Transparent;
			this->relock_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->relock_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->relock_btn->ForeColor = System::Drawing::Color::White;
			this->relock_btn->Location = System::Drawing::Point(420, 306);
			this->relock_btn->Name = L"relock_btn";
			this->relock_btn->Size = System::Drawing::Size(50, 50);
			this->relock_btn->TabIndex = 2;
			this->relock_btn->TabStop = false;
			this->relock_btn->Text = L"⏎";
			this->relock_btn->UseVisualStyleBackColor = false;
			this->relock_btn->Click += gcnew System::EventHandler(this, &main::relock_btn_Click);
			// 
			// pas_text
			// 
			this->pas_text->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pas_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pas_text->Location = System::Drawing::Point(196, 159);
			this->pas_text->Name = L"pas_text";
			this->pas_text->ReadOnly = true;
			this->pas_text->Size = System::Drawing::Size(274, 29);
			this->pas_text->TabIndex = 1;
			this->pas_text->TabStop = false;
			this->pas_text->WordWrap = false;
			// 
			// label
			// 
			this->label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label->AutoSize = true;
			this->label->BackColor = System::Drawing::Color::Transparent;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label->ForeColor = System::Drawing::Color::White;
			this->label->Location = System::Drawing::Point(190, 125);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(238, 31);
			this->label->TabIndex = 0;
			this->label->Text = L"Введите пароль:";
			this->label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(666, 480);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 350;
			this->timer1->Tick += gcnew System::EventHandler(this, &main::timer1_Tick);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 56.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(28, 365);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(609, 85);
			this->label1->TabIndex = 16;
			this->label1->Text = L"By. Lonewolf239";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(666, 480);
			this->Controls->Add(this->interface_panel);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Lock Guar v1.0";
			this->TopMost = true;
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &main::main_FormClosing);
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			this->interface_panel->ResumeLayout(false);
			this->interface_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void main_Load(System::Object^ sender, System::EventArgs^ e) {
		INIReader get_password(filePath);
		if (get_password.ParseError() < 0) {
			get_pas_form^ passwordForm = gcnew get_pas_form();
			this->now_closing = true;
			passwordForm->Show();
		}
		else {
			locked = get_password.GetBoolean("DATA", "locked", false);
			if (!locked) {
				Windows::Forms::DialogResult result = MessageBox::Show("Вы хотите заблокировать ПК?\n—————————————————\nДа:                        Заблокировать ПК\nНет:                          Сменить пароль\nОтмена:         Закрыть приложение", "Lock Guar v1.0 — Блокировка ПК", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
				if (result == Windows::Forms::DialogResult::Yes) {
					password = get_password.GetString("DATA", "password", "null");
					wchar_t path[MAX_PATH];
					HMODULE hModule = GetModuleHandle(NULL);
					GetModuleFileName(hModule, path, sizeof(path));
					HKEY hKey;
					std::wstring subKey = L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon";
					std::wstring valueName = L"Shell";
					std::wstring newValue = L"explorer.exe, ";
					newValue.append(path);
					if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, subKey.c_str(), 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
						RegSetValueEx(hKey, valueName.c_str(), 0, REG_SZ, reinterpret_cast<const BYTE*>(newValue.c_str()), (newValue.length() + 1) * sizeof(wchar_t));
						RegCloseKey(hKey);
					}
					subKey = L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System";
					valueName = L"DisableTaskMgr";
					DWORD newValue1 = 1;
					if (RegOpenKeyEx(HKEY_CURRENT_USER, subKey.c_str(), 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
						RegSetValueEx(hKey, valueName.c_str(), 0, REG_DWORD, (BYTE*)&newValue1, sizeof(newValue1));
						RegCloseKey(hKey);
					}
					if (!check()) {
						std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
						std::wstring widePath = converter.from_bytes(Path);
						CreateDirectoryW(widePath.c_str(), NULL);
					}
					std::ofstream did_pas(filePath);
					if (did_pas.is_open()) {
						did_pas << "[DATA]\npassword=" << password << "\nlocked=1\n";
						did_pas.close();
					}
					this->interface_panel->Visible = true;
					this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
				}
				else if (result == Windows::Forms::DialogResult::No) {
					this->ShowInTaskbar = false;
					get_pas_form^ passwordForm = gcnew get_pas_form();
					passwordForm->Show();
				}
				else {
					this->now_closing = true;
					Application::Exit();
				}
			}
			else {
				password = get_password.GetString("DATA", "password", "null");
				this->interface_panel->Visible = true;
				this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			}
		}
	}
	private: System::Void main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (!this->now_closing)
			e->Cancel = true;
		else
			UnhookKeyboardHook();
	}
	private: System::Void relock_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (msclr::interop::marshal_as<std::string>(this->pas_text->Text) == password) {
			HKEY hKey;
			std::wstring subKey = L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon";
			std::wstring valueName = L"Shell";
			std::wstring newValue = L"explorer.exe";
			if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, subKey.c_str(), 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
				RegSetValueEx(hKey, valueName.c_str(), 0, REG_SZ, reinterpret_cast<const BYTE*>(newValue.c_str()), (newValue.length() + 1) * sizeof(wchar_t));
				RegCloseKey(hKey);
			}
			subKey = L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System";
			valueName = L"DisableTaskMgr";
			DWORD newValue1 = 0;
			if (RegOpenKeyEx(HKEY_CURRENT_USER, subKey.c_str(), 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
				RegSetValueEx(hKey, valueName.c_str(), 0, REG_DWORD, (BYTE*)&newValue1, sizeof(newValue1));
				RegCloseKey(hKey);
			}
			this->now_closing = true;
			if (!check()) {
				std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
				std::wstring widePath = converter.from_bytes(Path);
				CreateDirectoryW(widePath.c_str(), NULL);
			}
			std::ofstream did_pas(filePath);
			if (did_pas.is_open()) {
				did_pas << "[DATA]\npassword=" << password << "\nlocked=0\n";
				did_pas.close();
			}
			Application::Exit();
		}
		else {
			MessageBox::Show("Неверный пароль!", "Lock Guar — Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		resources1 = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources1->GetObject(L"background")));
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources1->GetObject(L"background")));
		this->timer1->Stop();
	}
	private: System::Void interface_panel_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		SetKeyboardHook();
		this->timer1->Start();
	}
	private: System::Void num_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast <Button^>(sender);
		this->pas_text->Text += button->Text;
		this->num_symbol->Text = "Кол-во символов: " + this->pas_text->Text->Length;
	}
	private: System::Void clear_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pas_text->Text = "";
		this->num_symbol->Text = "Кол-во символов: " + this->pas_text->Text->Length;
	}
	private: System::Void clear_last_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ cat = this->pas_text->Text;
		if (cat->Length > 0)
			cat = cat->Remove(cat->Length - 1, 1);
		this->pas_text->Text = cat;
		this->num_symbol->Text = "Кол-во символов: " + this->pas_text->Text->Length;
	}
	};
}