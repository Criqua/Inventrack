#pragma once
#include "archivos_cAcceso.h"
#include "SystemString_toStdString.h"
#include "Validaciones.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Modificar_rolUsuario
	/// </summary>
	public ref class Modificar_rolUsuario : public System::Windows::Forms::Form
	{
	public:
		Modificar_rolUsuario(void)
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
		~Modificar_rolUsuario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	protected:
	public: System::Windows::Forms::ComboBox^ cb_rol;
	private:
	private: System::Windows::Forms::Label^ lbl_rol;
	public:
	public: System::Windows::Forms::ComboBox^ cb_usuario;
	private:
	private: System::Windows::Forms::Label^ lbl_user;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::Button^ btn_cancelar;
	private: System::Windows::Forms::Button^ btn_modificar;
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
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->cb_usuario = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_user = (gcnew System::Windows::Forms::Label());
			this->cb_rol = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_rol = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->btn_modificar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->panel_shadowing->SuspendLayout();
			this->SuspendLayout();
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// cb_usuario
			// 
			this->cb_usuario->FormattingEnabled = true;
			this->cb_usuario->Location = System::Drawing::Point(28, 51);
			this->cb_usuario->Name = L"cb_usuario";
			this->cb_usuario->Size = System::Drawing::Size(180, 21);
			this->cb_usuario->TabIndex = 14;
			this->cb_usuario->SelectedIndexChanged += gcnew System::EventHandler(this, &Modificar_rolUsuario::cb_usuario_SelectedIndexChanged);
			// 
			// lbl_user
			// 
			this->lbl_user->AutoSize = true;
			this->lbl_user->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_user->Location = System::Drawing::Point(24, 28);
			this->lbl_user->Name = L"lbl_user";
			this->lbl_user->Size = System::Drawing::Size(57, 19);
			this->lbl_user->TabIndex = 13;
			this->lbl_user->Text = L"Usuario";
			// 
			// cb_rol
			// 
			this->cb_rol->FormattingEnabled = true;
			this->cb_rol->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Administrador", L"Solo inventario", L"Solo factura",
					L"Inventario y factura"
			});
			this->cb_rol->Location = System::Drawing::Point(251, 51);
			this->cb_rol->Name = L"cb_rol";
			this->cb_rol->Size = System::Drawing::Size(180, 21);
			this->cb_rol->TabIndex = 16;
			// 
			// lbl_rol
			// 
			this->lbl_rol->AutoSize = true;
			this->lbl_rol->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_rol->Location = System::Drawing::Point(247, 28);
			this->lbl_rol->Name = L"lbl_rol";
			this->lbl_rol->Size = System::Drawing::Size(30, 19);
			this->lbl_rol->TabIndex = 15;
			this->lbl_rol->Text = L"Rol";
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_cancelar);
			this->panel_shadowing->Controls->Add(this->btn_modificar);
			this->panel_shadowing->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_shadowing->Location = System::Drawing::Point(0, 114);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(455, 74);
			this->panel_shadowing->TabIndex = 17;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_cancelar->ForeColor = System::Drawing::Color::White;
			this->btn_cancelar->Location = System::Drawing::Point(231, 22);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(125, 30);
			this->btn_cancelar->TabIndex = 19;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Modificar_rolUsuario::btn_cancelar_Click);
			// 
			// btn_modificar
			// 
			this->btn_modificar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_modificar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_modificar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_modificar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_modificar->ForeColor = System::Drawing::Color::White;
			this->btn_modificar->Location = System::Drawing::Point(99, 22);
			this->btn_modificar->Name = L"btn_modificar";
			this->btn_modificar->Size = System::Drawing::Size(125, 30);
			this->btn_modificar->TabIndex = 18;
			this->btn_modificar->Text = L"Guardar cambios";
			this->btn_modificar->UseVisualStyleBackColor = false;
			this->btn_modificar->Click += gcnew System::EventHandler(this, &Modificar_rolUsuario::btn_modificar_Click);
			// 
			// Modificar_rolUsuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(455, 188);
			this->Controls->Add(this->panel_shadowing);
			this->Controls->Add(this->cb_rol);
			this->Controls->Add(this->lbl_rol);
			this->Controls->Add(this->cb_usuario);
			this->Controls->Add(this->lbl_user);
			this->MaximizeBox = false;
			this->Name = L"Modificar_rolUsuario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modificar rol de los usuarios";
			this->Load += gcnew System::EventHandler(this, &Modificar_rolUsuario::Modificar_rolUsuario_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->panel_shadowing->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Modificar_rolUsuario_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se muestran los usuarios disponibles
		archivoAcceso::mostrarUsuarios(cb_usuario);
	}
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btn_modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		// Se definen algunos mensajes de error en caso de excepciones
		String^ emptyUserCB_box = "Debe seleccionar un usuario.";
		String^ emptyRoleCB_box = "Debe seleccionar un rol.";
		// Verificamos que los comboboxes no estén vacíos
		validate::isComboBox_notEmpty(cb_usuario, errorProvider, emptyUserCB_box, error);
		validate::isComboBox_notEmpty(cb_usuario, errorProvider, emptyUserCB_box, error);

		// En caso de ser así, se interrumpe el proceso de modificación
		if (error > 0) {
			return;
		}

		string selectedClient = conversion::to_stdstring(cb_usuario->SelectedItem->ToString());
		// Obtendremos el nombre del cliente antes de que llegue al caracter " ("
		stringstream ss(selectedClient);
		string username, uN, uID, currentRole;
		getline(ss, username, '(');
		// Eliminamos el espacio adicional al final " ("
		username = username.substr(0, username.size() - 1);

		string role = conversion::to_stdstring(cb_rol->SelectedItem->ToString());
		// Enviamos los valores a la función que modificará el rol
		archivoAcceso::modificarRol(username, role);

		MessageBox::Show("Rol modificado exitosamente.", "Modificación exitosa", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void cb_usuario_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Al momento de elegir un ítem del comboBox de usuarios, mostraeremos el rol que posee actualmente
		string selectedClient = conversion::to_stdstring(cb_usuario->SelectedItem->ToString());

		// Obtendremos el nombre del cliente antes de que llegue al caracter " ("
		stringstream ss(selectedClient);
		string username, uN, uID, currentRole;
		getline(ss, username, '(');
		// Eliminamos el espacio adicional al final " ("
		username = username.substr(0, username.size() - 1);

		// Llamamos a la función que buscará al usuario y extraerá sus datos, aunque solamente tomemos el rol actual
		archivoAcceso::buscarUsuario(username, uN, uID, currentRole);

		// Mostramos en el otro comboBox qué rol tiene el usuario actualmente
		cb_rol->Text = gcnew String(currentRole.c_str());
	}
	};
}
