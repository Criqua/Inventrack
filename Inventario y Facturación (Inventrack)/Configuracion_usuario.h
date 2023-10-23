#pragma once
#include "Agregar_usuario.h"
#include "Eliminar_usuario.h"
#include "Modificar_rolUsuario.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Configuracion_usuario
	/// </summary>
	public ref class Configuracion_usuario : public System::Windows::Forms::Form
	{
	public:
		Configuracion_usuario(void)
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
		~Configuracion_usuario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_addUser;
	private: System::Windows::Forms::Button^ btn_modifyUser;
	protected:

	protected:

	private: System::Windows::Forms::Button^ btn_delUser;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_addUser = (gcnew System::Windows::Forms::Button());
			this->btn_modifyUser = (gcnew System::Windows::Forms::Button());
			this->btn_delUser = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_addUser
			// 
			this->btn_addUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_addUser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_addUser->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_addUser->Location = System::Drawing::Point(12, 12);
			this->btn_addUser->Name = L"btn_addUser";
			this->btn_addUser->Size = System::Drawing::Size(424, 49);
			this->btn_addUser->TabIndex = 3;
			this->btn_addUser->Text = L"   Añadir usuarios";
			this->btn_addUser->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_addUser->UseVisualStyleBackColor = false;
			this->btn_addUser->Click += gcnew System::EventHandler(this, &Configuracion_usuario::btn_addUser_Click);
			// 
			// btn_modifyUser
			// 
			this->btn_modifyUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_modifyUser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_modifyUser->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_modifyUser->Location = System::Drawing::Point(12, 122);
			this->btn_modifyUser->Name = L"btn_modifyUser";
			this->btn_modifyUser->Size = System::Drawing::Size(424, 49);
			this->btn_modifyUser->TabIndex = 4;
			this->btn_modifyUser->Text = L"   Modificar roles de los usuarios";
			this->btn_modifyUser->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_modifyUser->UseVisualStyleBackColor = false;
			this->btn_modifyUser->Click += gcnew System::EventHandler(this, &Configuracion_usuario::btn_modifyUser_Click);
			// 
			// btn_delUser
			// 
			this->btn_delUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_delUser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_delUser->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_delUser->Location = System::Drawing::Point(12, 67);
			this->btn_delUser->Name = L"btn_delUser";
			this->btn_delUser->Size = System::Drawing::Size(424, 49);
			this->btn_delUser->TabIndex = 5;
			this->btn_delUser->Text = L"   Eliminar usuarios";
			this->btn_delUser->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_delUser->UseVisualStyleBackColor = false;
			this->btn_delUser->Click += gcnew System::EventHandler(this, &Configuracion_usuario::btn_delUser_Click);
			// 
			// Configuracion_usuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 183);
			this->Controls->Add(this->btn_delUser);
			this->Controls->Add(this->btn_modifyUser);
			this->Controls->Add(this->btn_addUser);
			this->MaximizeBox = false;
			this->Name = L"Configuracion_usuario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Seleccione una opción";
			this->Load += gcnew System::EventHandler(this, &Configuracion_usuario::Configuracion_usuario_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Configuracion_usuario_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_addUser_Click(System::Object^ sender, System::EventArgs^ e) {
		Inventrack::Agregar_usuario^ Agg = gcnew Inventrack::Agregar_usuario();
		Agg->Show();
	}
	private: System::Void btn_delUser_Click(System::Object^ sender, System::EventArgs^ e) {
		Inventrack::Eliminar_usuario^ Elim = gcnew Inventrack::Eliminar_usuario();
		Elim->Show();
	}
	private: System::Void btn_modifyUser_Click(System::Object^ sender, System::EventArgs^ e) {
		Inventrack::Modificar_rolUsuario^ Mod = gcnew Inventrack::Modificar_rolUsuario();
		Mod->Show();
	}
	};
}
