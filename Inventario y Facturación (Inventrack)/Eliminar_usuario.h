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
	/// Resumen de Eliminar_usuario
	/// </summary>
	public ref class Eliminar_usuario : public System::Windows::Forms::Form
	{
	public:
		Eliminar_usuario(void)
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
		~Eliminar_usuario()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Panel^ panel_info;

	private: System::Windows::Forms::Label^ lbl_rol;
	private: System::Windows::Forms::Label^ lbl_codId;
	private: System::Windows::Forms::Label^ lbl_nom;
	private: System::Windows::Forms::Label^ lbl_inf;
	private: System::Windows::Forms::Label^ lbl_verRol;
	private: System::Windows::Forms::Label^ lbl_verCodigo;
	private: System::Windows::Forms::Label^ lbl_verNombre;
	private: System::Windows::Forms::Label^ lbl_descBusqueda;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::Button^ btn_cancelar;
	private: System::Windows::Forms::Button^ btn_eliminar;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ lbl_registro;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::PictureBox^ pictureBox_buscar;
	private: System::Windows::Forms::TextBox^ tb_busqueda;
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
			this->panel_info = (gcnew System::Windows::Forms::Panel());
			this->lbl_verRol = (gcnew System::Windows::Forms::Label());
			this->lbl_verCodigo = (gcnew System::Windows::Forms::Label());
			this->lbl_verNombre = (gcnew System::Windows::Forms::Label());
			this->lbl_rol = (gcnew System::Windows::Forms::Label());
			this->lbl_codId = (gcnew System::Windows::Forms::Label());
			this->lbl_nom = (gcnew System::Windows::Forms::Label());
			this->lbl_inf = (gcnew System::Windows::Forms::Label());
			this->lbl_descBusqueda = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->btn_eliminar = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->lbl_registro = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->pictureBox_buscar = (gcnew System::Windows::Forms::PictureBox());
			this->tb_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel_info->SuspendLayout();
			this->panel_shadowing->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_info
			// 
			this->panel_info->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->panel_info->BackColor = System::Drawing::Color::White;
			this->panel_info->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_info->Controls->Add(this->lbl_verRol);
			this->panel_info->Controls->Add(this->lbl_verCodigo);
			this->panel_info->Controls->Add(this->lbl_verNombre);
			this->panel_info->Controls->Add(this->lbl_rol);
			this->panel_info->Controls->Add(this->lbl_codId);
			this->panel_info->Controls->Add(this->lbl_nom);
			this->panel_info->Controls->Add(this->lbl_inf);
			this->panel_info->Location = System::Drawing::Point(9, 117);
			this->panel_info->Name = L"panel_info";
			this->panel_info->Size = System::Drawing::Size(366, 130);
			this->panel_info->TabIndex = 27;
			// 
			// lbl_verRol
			// 
			this->lbl_verRol->AutoSize = true;
			this->lbl_verRol->Location = System::Drawing::Point(171, 99);
			this->lbl_verRol->Name = L"lbl_verRol";
			this->lbl_verRol->Size = System::Drawing::Size(10, 13);
			this->lbl_verRol->TabIndex = 28;
			this->lbl_verRol->Text = L"-";
			// 
			// lbl_verCodigo
			// 
			this->lbl_verCodigo->AutoSize = true;
			this->lbl_verCodigo->Location = System::Drawing::Point(171, 52);
			this->lbl_verCodigo->Name = L"lbl_verCodigo";
			this->lbl_verCodigo->Size = System::Drawing::Size(10, 13);
			this->lbl_verCodigo->TabIndex = 27;
			this->lbl_verCodigo->Text = L"-";
			// 
			// lbl_verNombre
			// 
			this->lbl_verNombre->AutoSize = true;
			this->lbl_verNombre->Location = System::Drawing::Point(171, 75);
			this->lbl_verNombre->Name = L"lbl_verNombre";
			this->lbl_verNombre->Size = System::Drawing::Size(10, 13);
			this->lbl_verNombre->TabIndex = 26;
			this->lbl_verNombre->Text = L"-";
			// 
			// lbl_rol
			// 
			this->lbl_rol->AutoSize = true;
			this->lbl_rol->BackColor = System::Drawing::Color::White;
			this->lbl_rol->Location = System::Drawing::Point(123, 99);
			this->lbl_rol->Name = L"lbl_rol";
			this->lbl_rol->Size = System::Drawing::Size(26, 13);
			this->lbl_rol->TabIndex = 25;
			this->lbl_rol->Text = L"Rol:";
			// 
			// lbl_codId
			// 
			this->lbl_codId->AutoSize = true;
			this->lbl_codId->BackColor = System::Drawing::Color::White;
			this->lbl_codId->Location = System::Drawing::Point(26, 52);
			this->lbl_codId->Name = L"lbl_codId";
			this->lbl_codId->Size = System::Drawing::Size(123, 13);
			this->lbl_codId->TabIndex = 21;
			this->lbl_codId->Text = L"Código de identificación:";
			// 
			// lbl_nom
			// 
			this->lbl_nom->AutoSize = true;
			this->lbl_nom->BackColor = System::Drawing::Color::White;
			this->lbl_nom->Location = System::Drawing::Point(102, 75);
			this->lbl_nom->Name = L"lbl_nom";
			this->lbl_nom->Size = System::Drawing::Size(47, 13);
			this->lbl_nom->TabIndex = 24;
			this->lbl_nom->Text = L"Nombre:";
			// 
			// lbl_inf
			// 
			this->lbl_inf->AutoSize = true;
			this->lbl_inf->BackColor = System::Drawing::Color::White;
			this->lbl_inf->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_inf->Location = System::Drawing::Point(123, 10);
			this->lbl_inf->Name = L"lbl_inf";
			this->lbl_inf->Size = System::Drawing::Size(131, 14);
			this->lbl_inf->TabIndex = 19;
			this->lbl_inf->Text = L"Información del usuario";
			// 
			// lbl_descBusqueda
			// 
			this->lbl_descBusqueda->AutoSize = true;
			this->lbl_descBusqueda->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_descBusqueda->Location = System::Drawing::Point(24, 68);
			this->lbl_descBusqueda->Name = L"lbl_descBusqueda";
			this->lbl_descBusqueda->Size = System::Drawing::Size(0, 19);
			this->lbl_descBusqueda->TabIndex = 28;
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_cancelar);
			this->panel_shadowing->Controls->Add(this->btn_eliminar);
			this->panel_shadowing->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_shadowing->Location = System::Drawing::Point(0, 274);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(389, 74);
			this->panel_shadowing->TabIndex = 29;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_cancelar->ForeColor = System::Drawing::Color::White;
			this->btn_cancelar->Location = System::Drawing::Point(200, 20);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(101, 33);
			this->btn_cancelar->TabIndex = 19;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Eliminar_usuario::btn_cancelar_Click);
			// 
			// btn_eliminar
			// 
			this->btn_eliminar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_eliminar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_eliminar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_eliminar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_eliminar->ForeColor = System::Drawing::Color::White;
			this->btn_eliminar->Location = System::Drawing::Point(85, 20);
			this->btn_eliminar->Name = L"btn_eliminar";
			this->btn_eliminar->Size = System::Drawing::Size(101, 33);
			this->btn_eliminar->TabIndex = 18;
			this->btn_eliminar->Text = L"Eliminar";
			this->btn_eliminar->UseVisualStyleBackColor = false;
			this->btn_eliminar->Click += gcnew System::EventHandler(this, &Eliminar_usuario::btn_eliminar_Click);
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel5->Controls->Add(this->lbl_registro);
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->label13);
			this->panel5->Location = System::Drawing::Point(38, 13);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(299, 32);
			this->panel5->TabIndex = 30;
			// 
			// lbl_registro
			// 
			this->lbl_registro->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_registro->AutoSize = true;
			this->lbl_registro->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_registro->ForeColor = System::Drawing::SystemColors::InfoText;
			this->lbl_registro->Location = System::Drawing::Point(79, 7);
			this->lbl_registro->Name = L"lbl_registro";
			this->lbl_registro->Size = System::Drawing::Size(150, 17);
			this->lbl_registro->TabIndex = 0;
			this->lbl_registro->Text = L"Eliminación de usuarios";
			this->lbl_registro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 2;
			// 
			// pictureBox_buscar
			// 
			this->pictureBox_buscar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox_buscar->Location = System::Drawing::Point(340, 75);
			this->pictureBox_buscar->Name = L"pictureBox_buscar";
			this->pictureBox_buscar->Size = System::Drawing::Size(17, 17);
			this->pictureBox_buscar->TabIndex = 31;
			this->pictureBox_buscar->TabStop = false;
			this->pictureBox_buscar->Click += gcnew System::EventHandler(this, &Eliminar_usuario::pictureBox_buscar_Click);
			// 
			// tb_busqueda
			// 
			this->tb_busqueda->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_busqueda->Location = System::Drawing::Point(23, 73);
			this->tb_busqueda->Multiline = true;
			this->tb_busqueda->Name = L"tb_busqueda";
			this->tb_busqueda->Size = System::Drawing::Size(337, 22);
			this->tb_busqueda->TabIndex = 32;
			this->tb_busqueda->Enter += gcnew System::EventHandler(this, &Eliminar_usuario::tb_busqueda_Enter);
			this->tb_busqueda->Leave += gcnew System::EventHandler(this, &Eliminar_usuario::tb_busqueda_Leave);
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Eliminar_usuario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(389, 348);
			this->Controls->Add(this->pictureBox_buscar);
			this->Controls->Add(this->tb_busqueda);
			this->Controls->Add(this->panel_shadowing);
			this->Controls->Add(this->lbl_descBusqueda);
			this->Controls->Add(this->panel_info);
			this->Controls->Add(this->panel5);
			this->MaximizeBox = false;
			this->Name = L"Eliminar_usuario";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Eliminar usuario";
			this->Load += gcnew System::EventHandler(this, &Eliminar_usuario::Eliminar_usuario_Load);
			this->panel_info->ResumeLayout(false);
			this->panel_info->PerformLayout();
			this->panel_shadowing->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Eliminar_usuario_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se carga el placeholder del textbox de búsqueda
		this->tb_busqueda->Text = default_text;

		// Se carga una imagen que simula una lupa en el buscador
		this->pictureBox_buscar->Image = Image::FromFile("imagenbuscar.png");
	}
	// Por motivos de mayor entendimiento a la eliminación, se darán indicaciones adicionales con texto como placeholders
	private: System::String^ default_text = "Buscar usuarios por nombre o por código...";
	private: System::Void tb_busqueda_Enter(System::Object^ sender, System::EventArgs^ e) {
		// Borra el texto predeterminado cuando el control TextBox obtiene el foco
		if (tb_busqueda->Text == default_text) {
			tb_busqueda->Text = "";
			tb_busqueda->ForeColor = SystemColors::WindowText;
			tb_busqueda->ReadOnly = false;
		}
	}
	private: System::Void tb_busqueda_Leave(System::Object^ sender, System::EventArgs^ e) {
		// Restaura el texto predeterminado si el usuario no ingresó nada
		if (this->tb_busqueda->Text == "") {
			this->tb_busqueda->Text = default_text;
			this->tb_busqueda->ForeColor = SystemColors::InactiveCaption;
			tb_busqueda->ReadOnly = true;
		}
	}
	private: System::Void pictureBox_buscar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener el valor del TextBox
		String^ searchedDesc = this->tb_busqueda->Text;

		// Si no se ha ingresado nada en el buscador y aún así se quiere buscar, se lanzarán un mensaje de error
		if (searchedDesc == default_text || searchedDesc->Trim() == "") {
			MessageBox::Show("Debe de indicar el nombre o código de un cliente para comenzar con la búsqueda. ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Stop);
		}
		else {
			// Declaramos variables que permitirán mostrar una vista previa de la información del usuario buscado
			string searchedUser = conversion::to_stdstring(tb_busqueda->Text);
			string userCode = "-";
			string username = "-";
			string userRole = "-";
			// Llamamos a la función que permitirá la búsqueda del usuario
			archivoAcceso::buscarUsuario(searchedUser, username, userCode, userRole);

			// Si la búsqueda fue exitosa, enviamos la información a los labels
			lbl_verNombre->Text = gcnew String(username.c_str());
			lbl_verCodigo->Text = gcnew String(userCode.c_str());
			lbl_verRol->Text = gcnew String(userRole.c_str());
		}
	}
	private: System::Void btn_eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		/* En caso de que el usuario desea eliminar un usuario y estos campos contienen el caracter "-",...
		...significa que no se ha buscado un usuario válido; por tanto, denegamos la eliminación*/
		if (lbl_verNombre->Text == "-" && lbl_verCodigo->Text == "-" && lbl_verRol->Text == "-") {
			MessageBox::Show("Debe buscar un cliente al cual eliminar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (lbl_verRol->Text == "Administrador") {
			System::Windows::Forms::DialogResult result = MessageBox::Show("El usuario al que desea eliminar es un administrador ¿Estás seguro que deseas continuar? Esta acción no se puede deshacer.",
				"Eliminación de un administrador", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				// El usuario decidió eliminar el usuario; por tanto, llamamos a la función que lo realizará
				string userToDelete = conversion::to_stdstring(lbl_verCodigo->Text);
				archivoAcceso::eliminarUsuario(userToDelete);
			}
			else {
				// El usuario decidió no eliminar el usuario; no hacemos nada
				return;
			}
		}
		else {
			// Le preguntamos al usuario de nuevo si en realidad quiere eliminar a dicho usuario
			System::Windows::Forms::DialogResult result = MessageBox::Show("¿Estás seguro de que deseas eliminar este usuario? Esta acción no se puede deshacer.",
				"Comprobar eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				// El usuario decidió eliminar el usuario; por tanto, llamamos a la función que lo realizará
				string userToDelete = conversion::to_stdstring(lbl_verCodigo->Text);
				archivoAcceso::eliminarUsuario(userToDelete);
			}
			else {
				// El usuario decidió no eliminar el usuario; no hacemos nada
				return;
			}
		}
	}
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
