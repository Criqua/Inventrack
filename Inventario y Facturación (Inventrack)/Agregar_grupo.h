#pragma once
#include "grupos/agregarGrupo.h"
#include "SystemString_toStdString.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de Agregar_grupo
	/// </summary>
	public ref class Agregar_grupo : public System::Windows::Forms::Form
	{

	public:
		Agregar_grupo(void)
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
		~Agregar_grupo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_group;
	private: System::Windows::Forms::TextBox^ tb_newgroup;
	private: System::Windows::Forms::Button^ btn_agregar;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->lbl_group = (gcnew System::Windows::Forms::Label());
			this->tb_newgroup = (gcnew System::Windows::Forms::TextBox());
			this->btn_agregar = (gcnew System::Windows::Forms::Button());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_group
			// 
			this->lbl_group->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 10, System::Drawing::FontStyle::Bold));
			this->lbl_group->Location = System::Drawing::Point(21, 41);
			this->lbl_group->Name = L"lbl_group";
			this->lbl_group->Size = System::Drawing::Size(101, 19);
			this->lbl_group->TabIndex = 2;
			this->lbl_group->Text = L"Nuevo grupo";
			this->lbl_group->Click += gcnew System::EventHandler(this, &Agregar_grupo::lbl_group_Click);
			// 
			// tb_newgroup
			// 
			this->tb_newgroup->BackColor = System::Drawing::Color::White;
			this->tb_newgroup->Location = System::Drawing::Point(128, 41);
			this->tb_newgroup->Name = L"tb_newgroup";
			this->tb_newgroup->Size = System::Drawing::Size(126, 20);
			this->tb_newgroup->TabIndex = 16;
			this->tb_newgroup->TextChanged += gcnew System::EventHandler(this, &Agregar_grupo::tb_newgroup_TextChanged);
			// 
			// btn_agregar
			// 
			this->btn_agregar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_agregar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_agregar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_agregar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_agregar->ForeColor = System::Drawing::Color::White;
			this->btn_agregar->Location = System::Drawing::Point(99, 88);
			this->btn_agregar->Name = L"btn_agregar";
			this->btn_agregar->Size = System::Drawing::Size(82, 33);
			this->btn_agregar->TabIndex = 19;
			this->btn_agregar->Text = L"Agregar";
			this->btn_agregar->UseVisualStyleBackColor = false;
			this->btn_agregar->Click += gcnew System::EventHandler(this, &Agregar_grupo::btn_agregar_Click);
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Agregar_grupo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 149);
			this->Controls->Add(this->btn_agregar);
			this->Controls->Add(this->tb_newgroup);
			this->Controls->Add(this->lbl_group);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Agregar_grupo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Agregar grupo";
			this->Load += gcnew System::EventHandler(this, &Agregar_grupo::Agregar_grupo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void lbl_group_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tb_newgroup_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_agregar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->tb_newgroup->Text == "") {
			errorProvider->SetError(tb_newgroup, "Este campo es obligatorio.");
			return;
		}
		// Ruta del archivo del registro de grupos
		string filepath = "grupos\\Registro de grupos.txt";

		// Se convierte la cadena System::String a std::string para ser compatible al guardado en el archivo
		string addgroup = conversion::to_stdstring(this->tb_newgroup->Text);

		// Se guarda el nuevo grupo
		grupo::agregarGrupo(filepath, addgroup);

		// Mostrar mensaje de éxito
		MessageBox::Show("Su nuevo grupo ha sido guardado exitosamente. Ahora podrá elegirlo y utilizarlo de inmediato.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Se limpia el campo del textbox luego de guardarse
		this->tb_newgroup->Text = "";
	}
	private: System::Void Agregar_grupo_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
