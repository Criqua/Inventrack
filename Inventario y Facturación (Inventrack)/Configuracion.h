#pragma once
#include "SystemString_toStdString.h"
#include "Validaciones.h"
#include "Resumen_financiero.h"
#include "Configuracion_usuario.h"
#include "config/archivarConfiguracion.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Configuracion
	/// </summary>
	public ref class Configuracion : public System::Windows::Forms::Form
	{
	public:
		Configuracion(void)
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
		~Configuracion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_shadowing;
	protected:
	private: System::Windows::Forms::Button^ btn_guardar;
	private: System::Windows::Forms::Panel^ panel_headinfo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbl_config;
	private: System::Windows::Forms::TextBox^ tb_dirEmpresa;
	private: System::Windows::Forms::Label^ lbl_dirEmpresa;
	private: System::Windows::Forms::TextBox^ tb_nomEmpresa;
	private: System::Windows::Forms::Label^ lbl_nomEmpresa;
	private: System::Windows::Forms::TextBox^ tb_correoEmpresa;
	private: System::Windows::Forms::Label^ lbl_correoEmpresa;
	private: System::Windows::Forms::TextBox^ tb_telEmpresa;
	private: System::Windows::Forms::Label^ lbl_telEmpresa;
	private: System::Windows::Forms::Label^ label_linea;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label_opcion;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ btn_configusuario;
	// Declaramos variables que obtendrán los datos principales de un archivo de texto
	public: String^ nEmp = "";
	public: String^ tEmp = "";
	public: String^ eEmp = "";
	public: String^ dEmp = "";
	// Declaramos variables que obtendrán la información del usuario que inició sesión
	public: String^ username = "";
	private: System::Windows::Forms::Button^ btn_verSaldos;
	public:
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
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_verSaldos = (gcnew System::Windows::Forms::Button());
			this->btn_configusuario = (gcnew System::Windows::Forms::Button());
			this->label_opcion = (gcnew System::Windows::Forms::Label());
			this->label_linea = (gcnew System::Windows::Forms::Label());
			this->tb_correoEmpresa = (gcnew System::Windows::Forms::TextBox());
			this->lbl_correoEmpresa = (gcnew System::Windows::Forms::Label());
			this->tb_telEmpresa = (gcnew System::Windows::Forms::TextBox());
			this->lbl_telEmpresa = (gcnew System::Windows::Forms::Label());
			this->tb_dirEmpresa = (gcnew System::Windows::Forms::TextBox());
			this->lbl_dirEmpresa = (gcnew System::Windows::Forms::Label());
			this->tb_nomEmpresa = (gcnew System::Windows::Forms::TextBox());
			this->lbl_nomEmpresa = (gcnew System::Windows::Forms::Label());
			this->btn_guardar = (gcnew System::Windows::Forms::Button());
			this->panel_headinfo = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbl_config = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel_shadowing->SuspendLayout();
			this->panel_headinfo->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_verSaldos);
			this->panel_shadowing->Controls->Add(this->btn_configusuario);
			this->panel_shadowing->Controls->Add(this->label_opcion);
			this->panel_shadowing->Controls->Add(this->label_linea);
			this->panel_shadowing->Controls->Add(this->tb_correoEmpresa);
			this->panel_shadowing->Controls->Add(this->lbl_correoEmpresa);
			this->panel_shadowing->Controls->Add(this->tb_telEmpresa);
			this->panel_shadowing->Controls->Add(this->lbl_telEmpresa);
			this->panel_shadowing->Controls->Add(this->tb_dirEmpresa);
			this->panel_shadowing->Controls->Add(this->lbl_dirEmpresa);
			this->panel_shadowing->Controls->Add(this->tb_nomEmpresa);
			this->panel_shadowing->Controls->Add(this->lbl_nomEmpresa);
			this->panel_shadowing->Controls->Add(this->btn_guardar);
			this->panel_shadowing->Controls->Add(this->panel_headinfo);
			this->panel_shadowing->Controls->Add(this->panel1);
			this->panel_shadowing->Location = System::Drawing::Point(3, 2);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(711, 446);
			this->panel_shadowing->TabIndex = 11;
			// 
			// btn_verSaldos
			// 
			this->btn_verSaldos->BackColor = System::Drawing::Color::Azure;
			this->btn_verSaldos->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_verSaldos->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_verSaldos->ForeColor = System::Drawing::SystemColors::WindowText;
			this->btn_verSaldos->Location = System::Drawing::Point(12, 384);
			this->btn_verSaldos->Name = L"btn_verSaldos";
			this->btn_verSaldos->Size = System::Drawing::Size(249, 42);
			this->btn_verSaldos->TabIndex = 31;
			this->btn_verSaldos->Text = L"Ver resumen de inversiones e ingresos";
			this->btn_verSaldos->UseVisualStyleBackColor = false;
			this->btn_verSaldos->Click += gcnew System::EventHandler(this, &Configuracion::btn_verSaldos_Click);
			// 
			// btn_configusuario
			// 
			this->btn_configusuario->BackColor = System::Drawing::Color::Azure;
			this->btn_configusuario->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_configusuario->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_configusuario->ForeColor = System::Drawing::SystemColors::WindowText;
			this->btn_configusuario->Location = System::Drawing::Point(419, 384);
			this->btn_configusuario->Name = L"btn_configusuario";
			this->btn_configusuario->Size = System::Drawing::Size(274, 42);
			this->btn_configusuario->TabIndex = 30;
			this->btn_configusuario->Text = L"Configuración de los usuarios del sistema";
			this->btn_configusuario->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btn_configusuario->UseVisualStyleBackColor = false;
			this->btn_configusuario->Click += gcnew System::EventHandler(this, &Configuracion::btn_configusuario_Click);
			// 
			// label_opcion
			// 
			this->label_opcion->AutoSize = true;
			this->label_opcion->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label_opcion->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label_opcion->Location = System::Drawing::Point(249, 55);
			this->label_opcion->Name = L"label_opcion";
			this->label_opcion->Size = System::Drawing::Size(165, 19);
			this->label_opcion->TabIndex = 28;
			this->label_opcion->Text = L"Encabezado de la factura";
			// 
			// label_linea
			// 
			this->label_linea->AutoSize = true;
			this->label_linea->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label_linea->Location = System::Drawing::Point(229, 66);
			this->label_linea->Name = L"label_linea";
			this->label_linea->Size = System::Drawing::Size(205, 13);
			this->label_linea->TabIndex = 27;
			this->label_linea->Text = L"_________________________________";
			// 
			// tb_correoEmpresa
			// 
			this->tb_correoEmpresa->Location = System::Drawing::Point(184, 220);
			this->tb_correoEmpresa->Name = L"tb_correoEmpresa";
			this->tb_correoEmpresa->Size = System::Drawing::Size(295, 20);
			this->tb_correoEmpresa->TabIndex = 26;
			this->tb_correoEmpresa->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_correoEmpresa
			// 
			this->lbl_correoEmpresa->AutoSize = true;
			this->lbl_correoEmpresa->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_correoEmpresa->Location = System::Drawing::Point(272, 202);
			this->lbl_correoEmpresa->Name = L"lbl_correoEmpresa";
			this->lbl_correoEmpresa->Size = System::Drawing::Size(118, 15);
			this->lbl_correoEmpresa->TabIndex = 25;
			this->lbl_correoEmpresa->Text = L"Correo de la empresa";
			// 
			// tb_telEmpresa
			// 
			this->tb_telEmpresa->Location = System::Drawing::Point(184, 169);
			this->tb_telEmpresa->Name = L"tb_telEmpresa";
			this->tb_telEmpresa->Size = System::Drawing::Size(295, 20);
			this->tb_telEmpresa->TabIndex = 24;
			this->tb_telEmpresa->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_telEmpresa
			// 
			this->lbl_telEmpresa->AutoSize = true;
			this->lbl_telEmpresa->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_telEmpresa->Location = System::Drawing::Point(267, 151);
			this->lbl_telEmpresa->Name = L"lbl_telEmpresa";
			this->lbl_telEmpresa->Size = System::Drawing::Size(129, 15);
			this->lbl_telEmpresa->TabIndex = 23;
			this->lbl_telEmpresa->Text = L"Teléfono de la empresa";
			// 
			// tb_dirEmpresa
			// 
			this->tb_dirEmpresa->Location = System::Drawing::Point(184, 271);
			this->tb_dirEmpresa->Name = L"tb_dirEmpresa";
			this->tb_dirEmpresa->Size = System::Drawing::Size(295, 20);
			this->tb_dirEmpresa->TabIndex = 22;
			this->tb_dirEmpresa->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_dirEmpresa
			// 
			this->lbl_dirEmpresa->AutoSize = true;
			this->lbl_dirEmpresa->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_dirEmpresa->Location = System::Drawing::Point(264, 253);
			this->lbl_dirEmpresa->Name = L"lbl_dirEmpresa";
			this->lbl_dirEmpresa->Size = System::Drawing::Size(134, 15);
			this->lbl_dirEmpresa->TabIndex = 21;
			this->lbl_dirEmpresa->Text = L"Dirección de la empresa";
			// 
			// tb_nomEmpresa
			// 
			this->tb_nomEmpresa->Location = System::Drawing::Point(184, 119);
			this->tb_nomEmpresa->Name = L"tb_nomEmpresa";
			this->tb_nomEmpresa->Size = System::Drawing::Size(295, 20);
			this->tb_nomEmpresa->TabIndex = 20;
			this->tb_nomEmpresa->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_nomEmpresa
			// 
			this->lbl_nomEmpresa->AutoSize = true;
			this->lbl_nomEmpresa->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nomEmpresa->Location = System::Drawing::Point(268, 101);
			this->lbl_nomEmpresa->Name = L"lbl_nomEmpresa";
			this->lbl_nomEmpresa->Size = System::Drawing::Size(127, 15);
			this->lbl_nomEmpresa->TabIndex = 19;
			this->lbl_nomEmpresa->Text = L"Nombre de la empresa";
			// 
			// btn_guardar
			// 
			this->btn_guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_guardar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_guardar->ForeColor = System::Drawing::Color::White;
			this->btn_guardar->Location = System::Drawing::Point(229, 314);
			this->btn_guardar->Name = L"btn_guardar";
			this->btn_guardar->Size = System::Drawing::Size(205, 35);
			this->btn_guardar->TabIndex = 18;
			this->btn_guardar->Text = L"Guardar cambios";
			this->btn_guardar->UseVisualStyleBackColor = false;
			this->btn_guardar->Click += gcnew System::EventHandler(this, &Configuracion::btn_guardar_Click);
			// 
			// panel_headinfo
			// 
			this->panel_headinfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_headinfo->Controls->Add(this->label1);
			this->panel_headinfo->Controls->Add(this->lbl_config);
			this->panel_headinfo->Location = System::Drawing::Point(3, 4);
			this->panel_headinfo->Name = L"panel_headinfo";
			this->panel_headinfo->Size = System::Drawing::Size(705, 33);
			this->panel_headinfo->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(10, 306);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 19);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Registrar productos";
			// 
			// lbl_config
			// 
			this->lbl_config->AutoSize = true;
			this->lbl_config->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_config->Location = System::Drawing::Point(10, 6);
			this->lbl_config->Name = L"lbl_config";
			this->lbl_config->Size = System::Drawing::Size(165, 19);
			this->lbl_config->TabIndex = 0;
			this->lbl_config->Text = L"Configuración y finanzas";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(161, 50);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(341, 33);
			this->panel1->TabIndex = 29;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(10, 306);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Registrar productos";
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Configuracion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(717, 451);
			this->Controls->Add(this->panel_shadowing);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Configuracion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Configuración";
			this->Load += gcnew System::EventHandler(this, &Configuracion::Configuracion_Load);
			this->panel_shadowing->ResumeLayout(false);
			this->panel_shadowing->PerformLayout();
			this->panel_headinfo->ResumeLayout(false);
			this->panel_headinfo->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Configuracion_Load(System::Object^ sender, System::EventArgs^ e) {
		// En caso de haber información configurada anteriormente, mostramos los datos del archivo
		archivoConfiguracion::verDatos(nEmp, dEmp, tEmp, eEmp);

		/* Mostramos una vista previa en los textboxes correspondientes acerca de los datos guardados en...
		...el archivo de configuración */
		tb_nomEmpresa->Text = nEmp;
		tb_dirEmpresa->Text = dEmp;
		tb_telEmpresa->Text = tEmp;
		tb_correoEmpresa->Text = eEmp;
	}
	private: System::Void btn_guardar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Administrador") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos. esta funcionalidad está limitada a los administradores del sistema.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		int error = 0;
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";
		// Se realizan validaciones antes de guardar los datos de configuración:

		// Verificamos si los textBoxes no están vacíos:
		validate::isTxtBox_notEmpty(tb_nomEmpresa, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_dirEmpresa, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_telEmpresa, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_correoEmpresa, errorProvider, emptyTxtBox_Message, error);

		// Se verifican si hubieron errores en el proceso
		if (error > 0) {
			return; // Si es así interrumpimos el proceso de guardado de datos
		}

		// Cambiamos de System::String a std::string los valores ingresados en la configuración
		string nom = conversion::to_stdstring(tb_nomEmpresa->Text);
		string dir = conversion::to_stdstring(tb_dirEmpresa->Text);
		string tel = conversion::to_stdstring(tb_telEmpresa->Text);
		string email = conversion::to_stdstring(tb_correoEmpresa->Text);

		archivoConfiguracion::guardarCambios(nom, dir, tel, email);

		MessageBox::Show("Configuración guardada exitosamente", "Cambios realizados", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void btn_configusuario_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Administrador") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos. esta funcionalidad está limitada a los administradores del sistema.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Abrimos el formulario de configuración de usuario en caso de ser administrador
		Inventrack::Configuracion_usuario^ config = gcnew Inventrack::Configuracion_usuario();
		config->Show();
	}
	private: System::Void btn_verSaldos_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Administrador") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos. esta funcionalidad está limitada a los administradores del sistema.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Abrimos el formulario de resumen financiero en caso de ser administrador
		Inventrack::Resumen_financiero^ resum = gcnew Inventrack::Resumen_financiero();
		resum->Show();
	}
	};
}