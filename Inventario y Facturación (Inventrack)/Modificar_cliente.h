#pragma once
#include "SystemString_toStdString.h"
#include "clientes/archivarClientes.h"
#include "Validaciones.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de Modificar_cliente
	/// </summary>
	public ref class Modificar_cliente : public System::Windows::Forms::Form
	{
	public:
		Modificar_cliente(void)
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
		~Modificar_cliente()
		{
			if (components)
			{
				delete components;
			}
		}
	public: String^ oldID = "";
	public: System::Windows::Forms::TextBox^ tb_cedula;
	protected:
	private: System::Windows::Forms::Label^ lbl_cedula;
	public:
	public: System::Windows::Forms::TextBox^ tb_tel;
	private:
	private: System::Windows::Forms::Label^ lbl_tel;
	public:
	public: System::Windows::Forms::TextBox^ tb_nombres;
	private:
	private: System::Windows::Forms::Label^ lbl_nombres;
	public: System::Windows::Forms::TextBox^ tb_apellidos;
	private:
	public:
	private:
	private: System::Windows::Forms::Label^ lbl_apellidos;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::Button^ btn_cancelar;
	private: System::Windows::Forms::Button^ btn_modificar;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::ComponentModel::IContainer^ components;
	// Se declara una variable booleana que permitirá saber si las validaciones son correctas o no
	public: bool validRegister;

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
			this->tb_cedula = (gcnew System::Windows::Forms::TextBox());
			this->lbl_cedula = (gcnew System::Windows::Forms::Label());
			this->tb_tel = (gcnew System::Windows::Forms::TextBox());
			this->lbl_tel = (gcnew System::Windows::Forms::Label());
			this->tb_nombres = (gcnew System::Windows::Forms::TextBox());
			this->lbl_nombres = (gcnew System::Windows::Forms::Label());
			this->tb_apellidos = (gcnew System::Windows::Forms::TextBox());
			this->lbl_apellidos = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->btn_modificar = (gcnew System::Windows::Forms::Button());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel_shadowing->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// tb_cedula
			// 
			this->tb_cedula->Location = System::Drawing::Point(16, 39);
			this->tb_cedula->Name = L"tb_cedula";
			this->tb_cedula->Size = System::Drawing::Size(362, 20);
			this->tb_cedula->TabIndex = 12;
			// 
			// lbl_cedula
			// 
			this->lbl_cedula->AutoSize = true;
			this->lbl_cedula->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_cedula->Location = System::Drawing::Point(12, 17);
			this->lbl_cedula->Name = L"lbl_cedula";
			this->lbl_cedula->Size = System::Drawing::Size(52, 19);
			this->lbl_cedula->TabIndex = 11;
			this->lbl_cedula->Text = L"Cédula";
			// 
			// tb_tel
			// 
			this->tb_tel->Location = System::Drawing::Point(16, 94);
			this->tb_tel->Name = L"tb_tel";
			this->tb_tel->Size = System::Drawing::Size(362, 20);
			this->tb_tel->TabIndex = 14;
			// 
			// lbl_tel
			// 
			this->lbl_tel->AutoSize = true;
			this->lbl_tel->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_tel->Location = System::Drawing::Point(12, 72);
			this->lbl_tel->Name = L"lbl_tel";
			this->lbl_tel->Size = System::Drawing::Size(63, 19);
			this->lbl_tel->TabIndex = 13;
			this->lbl_tel->Text = L"Teléfono";
			// 
			// tb_nombres
			// 
			this->tb_nombres->Location = System::Drawing::Point(16, 156);
			this->tb_nombres->Name = L"tb_nombres";
			this->tb_nombres->Size = System::Drawing::Size(362, 20);
			this->tb_nombres->TabIndex = 16;
			// 
			// lbl_nombres
			// 
			this->lbl_nombres->AutoSize = true;
			this->lbl_nombres->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_nombres->Location = System::Drawing::Point(12, 134);
			this->lbl_nombres->Name = L"lbl_nombres";
			this->lbl_nombres->Size = System::Drawing::Size(66, 19);
			this->lbl_nombres->TabIndex = 15;
			this->lbl_nombres->Text = L"Nombres";
			// 
			// tb_apellidos
			// 
			this->tb_apellidos->Location = System::Drawing::Point(16, 219);
			this->tb_apellidos->Name = L"tb_apellidos";
			this->tb_apellidos->Size = System::Drawing::Size(362, 20);
			this->tb_apellidos->TabIndex = 18;
			// 
			// lbl_apellidos
			// 
			this->lbl_apellidos->AutoSize = true;
			this->lbl_apellidos->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_apellidos->Location = System::Drawing::Point(12, 197);
			this->lbl_apellidos->Name = L"lbl_apellidos";
			this->lbl_apellidos->Size = System::Drawing::Size(67, 19);
			this->lbl_apellidos->TabIndex = 17;
			this->lbl_apellidos->Text = L"Apellidos";
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_cancelar);
			this->panel_shadowing->Controls->Add(this->btn_modificar);
			this->panel_shadowing->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_shadowing->Location = System::Drawing::Point(0, 265);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(401, 74);
			this->panel_shadowing->TabIndex = 19;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_cancelar->ForeColor = System::Drawing::Color::White;
			this->btn_cancelar->Location = System::Drawing::Point(199, 21);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(101, 33);
			this->btn_cancelar->TabIndex = 19;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Modificar_cliente::btn_cancelar_Click);
			// 
			// btn_modificar
			// 
			this->btn_modificar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_modificar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_modificar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_modificar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_modificar->ForeColor = System::Drawing::Color::White;
			this->btn_modificar->Location = System::Drawing::Point(80, 21);
			this->btn_modificar->Name = L"btn_modificar";
			this->btn_modificar->Size = System::Drawing::Size(101, 33);
			this->btn_modificar->TabIndex = 18;
			this->btn_modificar->Text = L"Modificar";
			this->btn_modificar->UseVisualStyleBackColor = false;
			this->btn_modificar->Click += gcnew System::EventHandler(this, &Modificar_cliente::btn_modificar_Click);
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Modificar_cliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(401, 339);
			this->Controls->Add(this->panel_shadowing);
			this->Controls->Add(this->tb_apellidos);
			this->Controls->Add(this->lbl_apellidos);
			this->Controls->Add(this->tb_nombres);
			this->Controls->Add(this->lbl_nombres);
			this->Controls->Add(this->tb_tel);
			this->Controls->Add(this->lbl_tel);
			this->Controls->Add(this->tb_cedula);
			this->Controls->Add(this->lbl_cedula);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Modificar_cliente";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modificar cliente";
			this->Load += gcnew System::EventHandler(this, &Modificar_cliente::Modificar_cliente_Load);
			this->panel_shadowing->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Modificar_cliente_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";
		// Se realizan validaciones antes del registro de los datos del producto:

		// 1. Verificamos si los textBoxes no están vacíos:
		validate::isTxtBox_notEmpty(tb_cedula, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_tel, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_nombres, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_apellidos, errorProvider, emptyTxtBox_Message, error);
		
		// Si en alguna de las validaciones hubo errores en la entrada de datos, interrumpimos el proceso de registro
		if (error > 0) {
			return;
		}
		// El usuario rellenó los datos de forma exitosa, procedemos al proceso de modificación de los datos
		string antID = conversion::to_stdstring(oldID);
		string ID = conversion::to_stdstring(tb_cedula->Text);
		string telf = conversion::to_stdstring(tb_tel->Text);
		string nom = conversion::to_stdstring(tb_nombres->Text);
		string ap = conversion::to_stdstring(tb_apellidos->Text);

		archivoCliente::modificarClientes(antID, ID, telf, nom, ap);
	}
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
