#pragma once
#include "SystemString_toStdString.h"
#include "Validaciones.h"
#include "archivos_cAcceso.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Agregar_usuario
	/// </summary>
	public ref class Agregar_usuario : public System::Windows::Forms::Form
	{
	public:
		Agregar_usuario(void)
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
		~Agregar_usuario()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ComboBox^ cb_rol;
	protected:
	private: System::Windows::Forms::Label^ lbl_rol;
	public:
	private: System::Windows::Forms::Label^ lbl_user;
	private: System::Windows::Forms::TextBox^ tb_usuario;

	private: System::Windows::Forms::TextBox^ tb_contra;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::Button^ btn_registrar;

	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::Windows::Forms::PictureBox^ pB_verContrasenia;
	private: System::Windows::Forms::Button^ btn_cancelar;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ lbl_registro;
	private: System::Windows::Forms::Label^ label13;
	private: System::ComponentModel::IContainer^ components;

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
			this->cb_rol = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_rol = (gcnew System::Windows::Forms::Label());
			this->lbl_user = (gcnew System::Windows::Forms::Label());
			this->tb_usuario = (gcnew System::Windows::Forms::TextBox());
			this->tb_contra = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->btn_registrar = (gcnew System::Windows::Forms::Button());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->pB_verContrasenia = (gcnew System::Windows::Forms::PictureBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbl_registro = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_verContrasenia))->BeginInit();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// cb_rol
			// 
			this->cb_rol->FormattingEnabled = true;
			this->cb_rol->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Administrador", L"Solo inventario", L"Solo factura",
					L"Inventario y factura"
			});
			this->cb_rol->Location = System::Drawing::Point(25, 212);
			this->cb_rol->Name = L"cb_rol";
			this->cb_rol->Size = System::Drawing::Size(205, 21);
			this->cb_rol->TabIndex = 20;
			// 
			// lbl_rol
			// 
			this->lbl_rol->AutoSize = true;
			this->lbl_rol->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_rol->Location = System::Drawing::Point(21, 189);
			this->lbl_rol->Name = L"lbl_rol";
			this->lbl_rol->Size = System::Drawing::Size(30, 19);
			this->lbl_rol->TabIndex = 19;
			this->lbl_rol->Text = L"Rol";
			// 
			// lbl_user
			// 
			this->lbl_user->AutoSize = true;
			this->lbl_user->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_user->Location = System::Drawing::Point(21, 60);
			this->lbl_user->Name = L"lbl_user";
			this->lbl_user->Size = System::Drawing::Size(100, 19);
			this->lbl_user->TabIndex = 17;
			this->lbl_user->Text = L"Nuevo usuario";
			// 
			// tb_usuario
			// 
			this->tb_usuario->Location = System::Drawing::Point(25, 82);
			this->tb_usuario->Name = L"tb_usuario";
			this->tb_usuario->Size = System::Drawing::Size(205, 20);
			this->tb_usuario->TabIndex = 21;
			// 
			// tb_contra
			// 
			this->tb_contra->Location = System::Drawing::Point(25, 148);
			this->tb_contra->Name = L"tb_contra";
			this->tb_contra->PasswordChar = '*';
			this->tb_contra->Size = System::Drawing::Size(205, 20);
			this->tb_contra->TabIndex = 23;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(21, 126);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 19);
			this->label1->TabIndex = 22;
			this->label1->Text = L"Contraseña";
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_cancelar);
			this->panel_shadowing->Controls->Add(this->btn_registrar);
			this->panel_shadowing->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_shadowing->Location = System::Drawing::Point(0, 281);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(267, 74);
			this->panel_shadowing->TabIndex = 26;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_cancelar->ForeColor = System::Drawing::Color::White;
			this->btn_cancelar->Location = System::Drawing::Point(136, 19);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(101, 33);
			this->btn_cancelar->TabIndex = 19;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Agregar_usuario::btn_cancelar_Click);
			// 
			// btn_registrar
			// 
			this->btn_registrar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_registrar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_registrar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_registrar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_registrar->ForeColor = System::Drawing::Color::White;
			this->btn_registrar->Location = System::Drawing::Point(29, 19);
			this->btn_registrar->Name = L"btn_registrar";
			this->btn_registrar->Size = System::Drawing::Size(101, 33);
			this->btn_registrar->TabIndex = 18;
			this->btn_registrar->Text = L"Registar";
			this->btn_registrar->UseVisualStyleBackColor = false;
			this->btn_registrar->Click += gcnew System::EventHandler(this, &Agregar_usuario::btn_registrar_Click);
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// pB_verContrasenia
			// 
			this->pB_verContrasenia->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pB_verContrasenia->Location = System::Drawing::Point(211, 150);
			this->pB_verContrasenia->Name = L"pB_verContrasenia";
			this->pB_verContrasenia->Size = System::Drawing::Size(17, 16);
			this->pB_verContrasenia->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_verContrasenia->TabIndex = 27;
			this->pB_verContrasenia->TabStop = false;
			this->pB_verContrasenia->Click += gcnew System::EventHandler(this, &Agregar_usuario::pB_verContrasenia_Click);
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->lbl_registro);
			this->panel5->Controls->Add(this->label13);
			this->panel5->Location = System::Drawing::Point(29, 11);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(199, 32);
			this->panel5->TabIndex = 28;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label11->Location = System::Drawing::Point(10, 306);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(132, 19);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Registrar productos";
			// 
			// lbl_registro
			// 
			this->lbl_registro->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_registro->AutoSize = true;
			this->lbl_registro->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_registro->ForeColor = System::Drawing::SystemColors::InfoText;
			this->lbl_registro->Location = System::Drawing::Point(38, 7);
			this->lbl_registro->Name = L"lbl_registro";
			this->lbl_registro->Size = System::Drawing::Size(126, 17);
			this->lbl_registro->TabIndex = 0;
			this->lbl_registro->Text = L"Registro de usuario";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 2;
			// 
			// Agregar_usuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(267, 355);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->pB_verContrasenia);
			this->Controls->Add(this->panel_shadowing);
			this->Controls->Add(this->tb_contra);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tb_usuario);
			this->Controls->Add(this->cb_rol);
			this->Controls->Add(this->lbl_rol);
			this->Controls->Add(this->lbl_user);
			this->MaximizeBox = false;
			this->Name = L"Agregar_usuario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Agregar usuario";
			this->Load += gcnew System::EventHandler(this, &Agregar_usuario::Agregar_usuario_Load);
			this->panel_shadowing->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_verContrasenia))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Agregar_usuario_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se carga una imagen que simular un ojo de ver contraseña
		Image^ imagenInicial = Image::FromFile("ojoabierto.png");
		imagenInicial->Tag = "ojoabierto.png";
		pB_verContrasenia->Image = imagenInicial;
	}
	private: System::Void pB_verContrasenia_Click(System::Object ^ sender, System::EventArgs ^ e) {
		// Se verifica si la imagen actual es un ojo abierto, si es así se cambia la imagen y se permite ver el contenido de contraseña
		if (pB_verContrasenia->Image != nullptr && pB_verContrasenia->Image->Tag != nullptr && pB_verContrasenia->Image->Tag->ToString() == "ojoabierto.png") {
			Image^ imagenInicial = Image::FromFile("ojocerrado.png");
			imagenInicial->Tag = "ojocerrado.png";
			pB_verContrasenia->Image = imagenInicial;
			this->tb_contra->PasswordChar = '\0';
		}
		else { // De otro modo, cambiamos la imagen a un ojo abierto y se oculta la contraseña
			Image^ imagenInicial = Image::FromFile("ojoabierto.png");
			imagenInicial->Tag = "ojoabierto.png";
			pB_verContrasenia->Image = imagenInicial;
			this->tb_contra->PasswordChar = '*';
		}
	}
	private: System::Void btn_registrar_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		// Se definen algunos mensajes de error en caso de excepciones
		String^ emptyUserCB_box = "Este campo es obligatorio.";

		// Verificamos que los campos no estén vacíos
		validate::isComboBox_notEmpty(cb_rol, errorProvider, emptyUserCB_box, error);
		validate::isTxtBox_notEmpty(tb_usuario, errorProvider, emptyUserCB_box, error);
		validate::isTxtBox_notEmpty(tb_contra, errorProvider, emptyUserCB_box, error);

		// En caso de ser así, se interrumpe el proceso de modificación
		if (error > 0) {
			return;
		}

		// Verificamos la estructura de la contraseña para hacerla lo más segura posible
		archivoAcceso::verificarContrasenia(tb_contra, errorProvider, error);

		// Volvemos a comprobar si no hubieron errores en el proceso
		if (error > 0) {
			return;
		}

		// Generamos un código aleatorio para identificar al nuevo usuario
		string code = archivoAcceso::generar_codigoUsuario();

		// Cambiamos los valores de las cajas de texto y desplegable a std::string
		string username = conversion::to_stdstring(tb_usuario->Text);
		string pword = conversion::to_stdstring(tb_contra->Text);
		string role = conversion::to_stdstring(cb_rol->Text);

		// Enviamos los valores a la función que registrará el nuevo usuario
		archivoAcceso::agregarUsuario(code, username, pword, role);

		// Mostramos un mensaje de registro exitoso, mostrando a la vez el código generado automáticamente
		MessageBox::Show("Usuario registrado exitosamente. Se le ha asignado un código único de identificación automáticamente: "
			+ gcnew String(code.c_str()), "Registro exitoso", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
