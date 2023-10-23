#pragma once
#include "proveedores/archivarProveedores.h"
#include "SystemString_toStdString.h"
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
	/// Resumen de Modificar_proveedor
	/// </summary>
	public ref class Modificar_proveedor : public System::Windows::Forms::Form
	{
	public:
		Modificar_proveedor(void)
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
		~Modificar_proveedor()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ tb_material;
	protected:
	private: System::Windows::Forms::Label^ lbl_material;
	public:
	public: System::Windows::Forms::TextBox^ tb_worksite;
	private:
	private: System::Windows::Forms::Label^ lbl_worksite;
	public:
	public: System::Windows::Forms::TextBox^ tb_surn;
	private:
	private: System::Windows::Forms::Label^ lbl_surn;
	public:
	public: System::Windows::Forms::TextBox^ tb_names;
	private:
	private: System::Windows::Forms::Label^ lbl_names;
	public:
	private: System::Windows::Forms::Label^ lbl_tel;
	public: System::Windows::Forms::TextBox^ tb_id;
	private:
	private: System::Windows::Forms::Panel^ panel_shadowing;
	public:
	private: System::Windows::Forms::Button^ btn_cancelar;
	private: System::Windows::Forms::Button^ btn_modificar;
	private: System::Windows::Forms::Label^ lbl_id;
	public: System::Windows::Forms::TextBox^ tb_tel;
	public: String^ ced = "";
	// Se declara una variable booleana que permitirá saber si las validaciones son correctas o no
	public: bool validRegister;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	public:
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
			this->tb_material = (gcnew System::Windows::Forms::TextBox());
			this->lbl_material = (gcnew System::Windows::Forms::Label());
			this->tb_worksite = (gcnew System::Windows::Forms::TextBox());
			this->lbl_worksite = (gcnew System::Windows::Forms::Label());
			this->tb_surn = (gcnew System::Windows::Forms::TextBox());
			this->lbl_surn = (gcnew System::Windows::Forms::Label());
			this->tb_names = (gcnew System::Windows::Forms::TextBox());
			this->lbl_names = (gcnew System::Windows::Forms::Label());
			this->lbl_tel = (gcnew System::Windows::Forms::Label());
			this->tb_id = (gcnew System::Windows::Forms::TextBox());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->btn_modificar = (gcnew System::Windows::Forms::Button());
			this->lbl_id = (gcnew System::Windows::Forms::Label());
			this->tb_tel = (gcnew System::Windows::Forms::TextBox());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel_shadowing->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// tb_material
			// 
			this->tb_material->Location = System::Drawing::Point(16, 299);
			this->tb_material->Name = L"tb_material";
			this->tb_material->Size = System::Drawing::Size(362, 20);
			this->tb_material->TabIndex = 35;
			// 
			// lbl_material
			// 
			this->lbl_material->AutoSize = true;
			this->lbl_material->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_material->Location = System::Drawing::Point(12, 277);
			this->lbl_material->Name = L"lbl_material";
			this->lbl_material->Size = System::Drawing::Size(61, 19);
			this->lbl_material->TabIndex = 34;
			this->lbl_material->Text = L"Material";
			// 
			// tb_worksite
			// 
			this->tb_worksite->Location = System::Drawing::Point(16, 248);
			this->tb_worksite->Name = L"tb_worksite";
			this->tb_worksite->Size = System::Drawing::Size(362, 20);
			this->tb_worksite->TabIndex = 33;
			// 
			// lbl_worksite
			// 
			this->lbl_worksite->AutoSize = true;
			this->lbl_worksite->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_worksite->Location = System::Drawing::Point(12, 226);
			this->lbl_worksite->Name = L"lbl_worksite";
			this->lbl_worksite->Size = System::Drawing::Size(111, 19);
			this->lbl_worksite->TabIndex = 32;
			this->lbl_worksite->Text = L"Lugar de trabajo";
			// 
			// tb_surn
			// 
			this->tb_surn->Location = System::Drawing::Point(16, 193);
			this->tb_surn->Name = L"tb_surn";
			this->tb_surn->Size = System::Drawing::Size(362, 20);
			this->tb_surn->TabIndex = 31;
			// 
			// lbl_surn
			// 
			this->lbl_surn->AutoSize = true;
			this->lbl_surn->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_surn->Location = System::Drawing::Point(12, 171);
			this->lbl_surn->Name = L"lbl_surn";
			this->lbl_surn->Size = System::Drawing::Size(67, 19);
			this->lbl_surn->TabIndex = 30;
			this->lbl_surn->Text = L"Apellidos";
			// 
			// tb_names
			// 
			this->tb_names->Location = System::Drawing::Point(16, 137);
			this->tb_names->Name = L"tb_names";
			this->tb_names->Size = System::Drawing::Size(362, 20);
			this->tb_names->TabIndex = 29;
			// 
			// lbl_names
			// 
			this->lbl_names->AutoSize = true;
			this->lbl_names->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_names->Location = System::Drawing::Point(12, 115);
			this->lbl_names->Name = L"lbl_names";
			this->lbl_names->Size = System::Drawing::Size(66, 19);
			this->lbl_names->TabIndex = 28;
			this->lbl_names->Text = L"Nombres";
			// 
			// lbl_tel
			// 
			this->lbl_tel->AutoSize = true;
			this->lbl_tel->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_tel->Location = System::Drawing::Point(12, 62);
			this->lbl_tel->Name = L"lbl_tel";
			this->lbl_tel->Size = System::Drawing::Size(63, 19);
			this->lbl_tel->TabIndex = 26;
			this->lbl_tel->Text = L"Teléfono";
			// 
			// tb_id
			// 
			this->tb_id->Location = System::Drawing::Point(16, 30);
			this->tb_id->Name = L"tb_id";
			this->tb_id->Size = System::Drawing::Size(362, 20);
			this->tb_id->TabIndex = 25;
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_cancelar);
			this->panel_shadowing->Controls->Add(this->btn_modificar);
			this->panel_shadowing->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_shadowing->Location = System::Drawing::Point(0, 338);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(404, 74);
			this->panel_shadowing->TabIndex = 24;
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
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Modificar_proveedor::btn_cancelar_Click);
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
			this->btn_modificar->Click += gcnew System::EventHandler(this, &Modificar_proveedor::btn_modificar_Click);
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_id->Location = System::Drawing::Point(12, 8);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(52, 19);
			this->lbl_id->TabIndex = 23;
			this->lbl_id->Text = L"Cédula";
			// 
			// tb_tel
			// 
			this->tb_tel->Location = System::Drawing::Point(16, 84);
			this->tb_tel->Name = L"tb_tel";
			this->tb_tel->Size = System::Drawing::Size(362, 20);
			this->tb_tel->TabIndex = 38;
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Modificar_proveedor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(404, 412);
			this->Controls->Add(this->tb_tel);
			this->Controls->Add(this->tb_material);
			this->Controls->Add(this->lbl_material);
			this->Controls->Add(this->tb_worksite);
			this->Controls->Add(this->lbl_worksite);
			this->Controls->Add(this->tb_surn);
			this->Controls->Add(this->lbl_surn);
			this->Controls->Add(this->tb_names);
			this->Controls->Add(this->lbl_names);
			this->Controls->Add(this->lbl_tel);
			this->Controls->Add(this->tb_id);
			this->Controls->Add(this->panel_shadowing);
			this->Controls->Add(this->lbl_id);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Modificar_proveedor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modificar proveedor";
			this->Load += gcnew System::EventHandler(this, &Modificar_proveedor::Modificar_proveedor_Load);
			this->panel_shadowing->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btn_modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";
		// Se realizan validaciones antes del registro de los datos del proveedor:

		// 1. Verificamos si los textBoxes no están vacíos:
		validate::isTxtBox_notEmpty(tb_id, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_tel, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_names, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_surn, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_worksite, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_material, errorProvider, emptyTxtBox_Message, error);

		// Si en alguna de las validaciones hubo errores en la entrada de datos, interrumpimos el proceso de modificación
		if (error > 0) {
			return;
		}
		// El usuario rellenó los datos de forma exitosa, procedemos al proceso de modificación de los datos
		string oldID = conversion::to_stdstring(ced);
		string newID = conversion::to_stdstring(this->tb_id->Text);
		string newtel = conversion::to_stdstring(this->tb_tel->Text);
		string newnames = conversion::to_stdstring(this->tb_names->Text);
		string newsurn = conversion::to_stdstring(this->tb_surn->Text);
		string newworksite = conversion::to_stdstring(this->tb_worksite->Text);
		string newmaterial = conversion::to_stdstring(this->tb_material->Text);

		archivoProveedores::modificarProveedores(oldID, newID, newtel, newnames, newsurn, newworksite, newmaterial);
	}
	private: System::Void Modificar_proveedor_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}