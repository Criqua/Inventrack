#pragma once
#include "Menu.h"
#include "SystemString_toStdString.h"
#include "archivos_cAcceso.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tb_username;
	private: System::Windows::Forms::PictureBox^ pB_logo;
	private: System::Windows::Forms::PictureBox^ pB_usuario;
	private: System::Windows::Forms::TextBox^ tb_password;
	private: System::Windows::Forms::PictureBox^ pB_password;
	private: System::Windows::Forms::Button^ btn_guardar;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::Windows::Forms::Panel^ panel;
	private: System::Windows::Forms::Button^ btn_salir;
	private: System::ComponentModel::IContainer^ components;
	public: String^ username = "";
	public: String^ role = "";
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_username = (gcnew System::Windows::Forms::TextBox());
			this->pB_logo = (gcnew System::Windows::Forms::PictureBox());
			this->pB_usuario = (gcnew System::Windows::Forms::PictureBox());
			this->tb_password = (gcnew System::Windows::Forms::TextBox());
			this->pB_password = (gcnew System::Windows::Forms::PictureBox());
			this->btn_guardar = (gcnew System::Windows::Forms::Button());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->btn_salir = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_logo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_usuario))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_password))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(202, 117);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(183, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Acceso a Inventrack";
			// 
			// tb_username
			// 
			this->tb_username->BackColor = System::Drawing::Color::Gainsboro;
			this->tb_username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_username->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semilight", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_username->Location = System::Drawing::Point(239, 185);
			this->tb_username->Multiline = true;
			this->tb_username->Name = L"tb_username";
			this->tb_username->Size = System::Drawing::Size(172, 30);
			this->tb_username->TabIndex = 2;
			this->tb_username->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_username->Enter += gcnew System::EventHandler(this, &Login::tb_username_Enter);
			this->tb_username->Leave += gcnew System::EventHandler(this, &Login::tb_username_Leave);
			// 
			// pB_logo
			// 
			this->pB_logo->Location = System::Drawing::Point(237, 35);
			this->pB_logo->Name = L"pB_logo";
			this->pB_logo->Size = System::Drawing::Size(118, 67);
			this->pB_logo->TabIndex = 4;
			this->pB_logo->TabStop = false;
			// 
			// pB_usuario
			// 
			this->pB_usuario->Location = System::Drawing::Point(179, 171);
			this->pB_usuario->Name = L"pB_usuario";
			this->pB_usuario->Size = System::Drawing::Size(59, 60);
			this->pB_usuario->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_usuario->TabIndex = 5;
			this->pB_usuario->TabStop = false;
			this->pB_usuario->Click += gcnew System::EventHandler(this, &Login::pB_usuario_Click);
			// 
			// tb_password
			// 
			this->tb_password->BackColor = System::Drawing::Color::Gainsboro;
			this->tb_password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tb_password->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semilight", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_password->Location = System::Drawing::Point(239, 266);
			this->tb_password->Multiline = true;
			this->tb_password->Name = L"tb_password";
			this->tb_password->PasswordChar = '*';
			this->tb_password->Size = System::Drawing::Size(172, 30);
			this->tb_password->TabIndex = 6;
			this->tb_password->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_password->Enter += gcnew System::EventHandler(this, &Login::tb_password_Enter);
			this->tb_password->Leave += gcnew System::EventHandler(this, &Login::tb_password_Leave);
			// 
			// pB_password
			// 
			this->pB_password->Location = System::Drawing::Point(179, 253);
			this->pB_password->Name = L"pB_password";
			this->pB_password->Size = System::Drawing::Size(59, 53);
			this->pB_password->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_password->TabIndex = 7;
			this->pB_password->TabStop = false;
			// 
			// btn_guardar
			// 
			this->btn_guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_guardar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_guardar->ForeColor = System::Drawing::Color::White;
			this->btn_guardar->Location = System::Drawing::Point(147, 348);
			this->btn_guardar->Name = L"btn_guardar";
			this->btn_guardar->Size = System::Drawing::Size(148, 35);
			this->btn_guardar->TabIndex = 19;
			this->btn_guardar->Text = L"Ingresar";
			this->btn_guardar->UseVisualStyleBackColor = false;
			this->btn_guardar->Click += gcnew System::EventHandler(this, &Login::btn_guardar_Click);
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// panel
			// 
			this->panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel->Controls->Add(this->btn_salir);
			this->panel->Location = System::Drawing::Point(3, 3);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(615, 440);
			this->panel->TabIndex = 20;
			// 
			// btn_salir
			// 
			this->btn_salir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_salir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_salir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_salir->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_salir->ForeColor = System::Drawing::Color::White;
			this->btn_salir->Location = System::Drawing::Point(307, 344);
			this->btn_salir->Name = L"btn_salir";
			this->btn_salir->Size = System::Drawing::Size(148, 35);
			this->btn_salir->TabIndex = 20;
			this->btn_salir->Text = L"Salir";
			this->btn_salir->UseVisualStyleBackColor = false;
			this->btn_salir->Click += gcnew System::EventHandler(this, &Login::btn_salir_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 445);
			this->Controls->Add(this->btn_guardar);
			this->Controls->Add(this->pB_password);
			this->Controls->Add(this->tb_password);
			this->Controls->Add(this->pB_usuario);
			this->Controls->Add(this->pB_logo);
			this->Controls->Add(this->tb_username);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_logo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_usuario))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_password))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->panel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se carga unos placeholder que contienen información
		this->tb_username->Text = usernamePlaceholder;
		this->tb_password->Text = passwordPlaceholder;
		this->tb_password->PasswordChar = '\0';

		// Se carga una imagen que simula un logo del sistema
		this->pB_logo->Image = Image::FromFile("imagenlogo.png");

		// Se carga una imagen que simula el ícono del campo de usuario
		this->pB_usuario->Image = Image::FromFile("imagenusuario.png");

		// Se carga una imagen que simula el ícono del campo de contraseña
		this->pB_password->Image = Image::FromFile("imagenpssword.png");

		// Recorremos todos los controles del formulario
		for each (Control ^ control in this->Controls) {
			// Establecemos TabStop en false para evitar que los textboxes tengan automaticamente el enfoque
			control->TabStop = false;
		}
	}
	private: System::Void btn_guardar_Click(System::Object^ sender, System::EventArgs^ e) {
		bool hasEntered; // Variable boolena que permitirá determinar si el inicio de sesión es correcto
		int error = 0; 
		// Redactamos un mensaje de error, al momento de validar las entradas
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";

		// Verificamos que los textboxes no estén vacíos
		validate::isTxtBox_notEmpty(tb_username, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_password, errorProvider, emptyTxtBox_Message, error);

		if (error > 0) {
			return;
		}

		// Si uno de los textboxes tienen los mismos placeholders, se considerarán como error
		if (tb_username->Text == usernamePlaceholder) {
			errorProvider->SetError(tb_username, emptyTxtBox_Message);
			error++;
		}
		else if (tb_password->Text == passwordPlaceholder) {
			errorProvider->SetError(tb_username, emptyTxtBox_Message);
			error++;
		}

		if (error > 0) {
			return;
		}
		
		// Cambiamos de System::String a std::string los valores en el TextBox;
		string usuario = conversion::to_stdstring(tb_username->Text);
		string contr = conversion::to_stdstring(tb_password->Text);
		// Se llama a esta función a fin de verificar si los textos de los textboxes coinciden con los registros
		archivoAcceso::verificarAcceso(usuario, contr, hasEntered, username, role);
	
		if (hasEntered == true) {
			/* Al acceder satisfactoriamente al sistema, se cierra el formulario de Login y se abre el Menú...
			...al crear una nueva instancia de él*/
			this->Visible = false;
			Inventrack::Menu^ Menu = gcnew Inventrack::Menu();
			Menu->userN = username;
			Menu->role = role;
			Menu->Show();
		}
		else{
			// Los datos de acceso fueron incorrectos; vaciamos los textboxes
			tb_username->Text = "";
			tb_password->Text = "";
			this->tb_username->Text = usernamePlaceholder;
			this->tb_password->Text = passwordPlaceholder;
			this->tb_password->PasswordChar = '\0';
		}
	}
	private: System::Void pB_usuario_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_salir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::String^ usernamePlaceholder = "Usuario";
	private: System::String^ passwordPlaceholder = "Contraseña";
	private: System::Void tb_username_Enter(System::Object^ sender, System::EventArgs^ e) {
		// Borra el texto predeterminado cuando el control TextBox obtiene el foco
		if (tb_username->Text == usernamePlaceholder) {
			tb_username->Text = "";
			tb_username->ReadOnly = false;
			// Al obtener el foco cambiamos la fuente de texto a predeterminado
			tb_password->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semilight", 12.1F, System::Drawing::FontStyle::Regular));
		}
	}
	private: System::Void tb_username_Leave(System::Object^ sender, System::EventArgs^ e) {
		// Restaura el texto predeterminado si el usuario no ingresó nada
		if (this->tb_username->Text == "") {
			this->tb_username->Text = usernamePlaceholder;
			tb_username->ReadOnly = true;
			// Al momento de no interactuar con el textbox, se usa una fuente de texto personalizada con estilo itálico
			tb_username->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12.1F, System::Drawing::FontStyle::Italic));
		}
	}
	private: System::Void tb_password_Enter(System::Object^ sender, System::EventArgs^ e) {
		// Borra el texto predeterminado cuando el control TextBox obtiene el foco
		if (tb_password->Text == passwordPlaceholder) {
			tb_password->Text = "";
			tb_password->ReadOnly = false;
			tb_password->PasswordChar = '*';
			// Al obtener el foco cambiamos la fuente de texto a predeterminado
			tb_password->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semilight", 12.1F, System::Drawing::FontStyle::Regular));
		}
	}
	private: System::Void tb_password_Leave(System::Object^ sender, System::EventArgs^ e) {
		// Restaura el texto predeterminado si el usuario no ingresó nada
		if (this->tb_password->Text == "") {
			this->tb_password->Text = passwordPlaceholder;
			tb_password->ReadOnly = true;
			tb_password->PasswordChar = '\0'; // Pasamos un valor nulo para que deje de mostrarse en formato de contraseña
			// Al momento de no interactuar con el textbox, se usa una fuente de texto personalizada con estilo itálico
			tb_password->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semilight", 12.1F, System::Drawing::FontStyle::Italic));
		}
	}
	};
}
