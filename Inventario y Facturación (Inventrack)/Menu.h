#pragma once
#include "Productos.h"
#include "Clientes.h"
#include "Proveedores.h"
#include "Factura.h"
#include "Configuracion.h"
#include "Alertas.h"
#include "productos/archivarProductos.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Menu : public System::Windows::Forms::Form
	{
	public:
		Menu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_menu;
	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::Button^ btn_settings;
	private: System::Windows::Forms::Button^ btn_bills;
	private: System::Windows::Forms::Button^ btn_providers;
	private: System::Windows::Forms::Button^ btn_clients;
	private: System::Windows::Forms::Button^ btn_products;
	private: System::Windows::Forms::Panel^ panel_header;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lbl_naming;
	private: System::Windows::Forms::Panel^ panel_info;
	private: System::Windows::Forms::PictureBox^ pB_alertas;
	private: System::Windows::Forms::Label^ lbl_noAlertas;
	private: System::Windows::Forms::Label^ label_saludo;
	private: System::Windows::Forms::Label^ lbl_siAlertas;
	// Variables que obtendrán los datos del usuario al acceder al sistema
	public: String^ userN = "";
	public: String^ role = "";
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel_menu = (gcnew System::Windows::Forms::Panel());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->btn_settings = (gcnew System::Windows::Forms::Button());
			this->btn_bills = (gcnew System::Windows::Forms::Button());
			this->btn_providers = (gcnew System::Windows::Forms::Button());
			this->btn_clients = (gcnew System::Windows::Forms::Button());
			this->btn_products = (gcnew System::Windows::Forms::Button());
			this->panel_header = (gcnew System::Windows::Forms::Panel());
			this->pB_alertas = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_naming = (gcnew System::Windows::Forms::Label());
			this->panel_info = (gcnew System::Windows::Forms::Panel());
			this->lbl_siAlertas = (gcnew System::Windows::Forms::Label());
			this->lbl_noAlertas = (gcnew System::Windows::Forms::Label());
			this->label_saludo = (gcnew System::Windows::Forms::Label());
			this->panel_menu->SuspendLayout();
			this->panel_header->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_alertas))->BeginInit();
			this->panel_info->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_menu
			// 
			this->panel_menu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->panel_menu->Controls->Add(this->btn_close);
			this->panel_menu->Controls->Add(this->btn_settings);
			this->panel_menu->Controls->Add(this->btn_bills);
			this->panel_menu->Controls->Add(this->btn_providers);
			this->panel_menu->Controls->Add(this->btn_clients);
			this->panel_menu->Controls->Add(this->btn_products);
			this->panel_menu->Controls->Add(this->panel_header);
			this->panel_menu->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel_menu->Location = System::Drawing::Point(0, 0);
			this->panel_menu->Name = L"panel_menu";
			this->panel_menu->Size = System::Drawing::Size(203, 451);
			this->panel_menu->TabIndex = 1;
			// 
			// btn_close
			// 
			this->btn_close->FlatAppearance->BorderSize = 0;
			this->btn_close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_close->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_close->ForeColor = System::Drawing::Color::White;
			this->btn_close->Location = System::Drawing::Point(0, 323);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(200, 44);
			this->btn_close->TabIndex = 6;
			this->btn_close->Text = L"     Salir";
			this->btn_close->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_close->UseVisualStyleBackColor = true;
			this->btn_close->Click += gcnew System::EventHandler(this, &Menu::btn_close_Click);
			// 
			// btn_settings
			// 
			this->btn_settings->FlatAppearance->BorderSize = 0;
			this->btn_settings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_settings->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_settings->ForeColor = System::Drawing::Color::White;
			this->btn_settings->Location = System::Drawing::Point(0, 273);
			this->btn_settings->Name = L"btn_settings";
			this->btn_settings->Size = System::Drawing::Size(200, 44);
			this->btn_settings->TabIndex = 5;
			this->btn_settings->Text = L"     Configuración y finanzas";
			this->btn_settings->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_settings->UseVisualStyleBackColor = true;
			this->btn_settings->Click += gcnew System::EventHandler(this, &Menu::btn_settings_Click);
			// 
			// btn_bills
			// 
			this->btn_bills->FlatAppearance->BorderSize = 0;
			this->btn_bills->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_bills->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_bills->ForeColor = System::Drawing::Color::White;
			this->btn_bills->Location = System::Drawing::Point(0, 223);
			this->btn_bills->Name = L"btn_bills";
			this->btn_bills->Size = System::Drawing::Size(200, 44);
			this->btn_bills->TabIndex = 4;
			this->btn_bills->Text = L"     Facturación";
			this->btn_bills->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_bills->UseVisualStyleBackColor = true;
			this->btn_bills->Click += gcnew System::EventHandler(this, &Menu::btn_bills_Click);
			// 
			// btn_providers
			// 
			this->btn_providers->FlatAppearance->BorderSize = 0;
			this->btn_providers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_providers->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_providers->ForeColor = System::Drawing::Color::White;
			this->btn_providers->Location = System::Drawing::Point(0, 173);
			this->btn_providers->Name = L"btn_providers";
			this->btn_providers->Size = System::Drawing::Size(200, 44);
			this->btn_providers->TabIndex = 3;
			this->btn_providers->Text = L"     Proveedores";
			this->btn_providers->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_providers->UseVisualStyleBackColor = true;
			this->btn_providers->Click += gcnew System::EventHandler(this, &Menu::btn_providers_Click);
			// 
			// btn_clients
			// 
			this->btn_clients->FlatAppearance->BorderSize = 0;
			this->btn_clients->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_clients->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_clients->ForeColor = System::Drawing::Color::White;
			this->btn_clients->Location = System::Drawing::Point(0, 123);
			this->btn_clients->Name = L"btn_clients";
			this->btn_clients->Size = System::Drawing::Size(200, 44);
			this->btn_clients->TabIndex = 2;
			this->btn_clients->Text = L"     Clientes";
			this->btn_clients->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_clients->UseVisualStyleBackColor = true;
			this->btn_clients->Click += gcnew System::EventHandler(this, &Menu::btn_clients_Click);
			// 
			// btn_products
			// 
			this->btn_products->FlatAppearance->BorderSize = 0;
			this->btn_products->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_products->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_products->ForeColor = System::Drawing::Color::White;
			this->btn_products->Location = System::Drawing::Point(0, 73);
			this->btn_products->Name = L"btn_products";
			this->btn_products->Size = System::Drawing::Size(200, 44);
			this->btn_products->TabIndex = 1;
			this->btn_products->Text = L"     Productos";
			this->btn_products->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_products->UseVisualStyleBackColor = true;
			this->btn_products->Click += gcnew System::EventHandler(this, &Menu::btn_products_Click);
			// 
			// panel_header
			// 
			this->panel_header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)));
			this->panel_header->Controls->Add(this->pB_alertas);
			this->panel_header->Controls->Add(this->panel1);
			this->panel_header->Controls->Add(this->lbl_naming);
			this->panel_header->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_header->Location = System::Drawing::Point(0, 0);
			this->panel_header->Name = L"panel_header";
			this->panel_header->Size = System::Drawing::Size(203, 71);
			this->panel_header->TabIndex = 0;
			// 
			// pB_alertas
			// 
			this->pB_alertas->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pB_alertas->Location = System::Drawing::Point(154, 12);
			this->pB_alertas->Name = L"pB_alertas";
			this->pB_alertas->Size = System::Drawing::Size(32, 24);
			this->pB_alertas->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_alertas->TabIndex = 3;
			this->pB_alertas->TabStop = false;
			this->pB_alertas->Click += gcnew System::EventHandler(this, &Menu::pB_alertas_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(206, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 100);
			this->panel1->TabIndex = 2;
			// 
			// lbl_naming
			// 
			this->lbl_naming->AutoSize = true;
			this->lbl_naming->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 12.75F, System::Drawing::FontStyle::Bold));
			this->lbl_naming->ForeColor = System::Drawing::Color::White;
			this->lbl_naming->Location = System::Drawing::Point(13, 13);
			this->lbl_naming->Name = L"lbl_naming";
			this->lbl_naming->Size = System::Drawing::Size(91, 23);
			this->lbl_naming->TabIndex = 0;
			this->lbl_naming->Text = L"Inventrack";
			// 
			// panel_info
			// 
			this->panel_info->AutoScroll = true;
			this->panel_info->Controls->Add(this->lbl_siAlertas);
			this->panel_info->Controls->Add(this->lbl_noAlertas);
			this->panel_info->Controls->Add(this->label_saludo);
			this->panel_info->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_info->Location = System::Drawing::Point(203, 0);
			this->panel_info->Name = L"panel_info";
			this->panel_info->Size = System::Drawing::Size(717, 451);
			this->panel_info->TabIndex = 2;
			// 
			// lbl_siAlertas
			// 
			this->lbl_siAlertas->AutoSize = true;
			this->lbl_siAlertas->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_siAlertas->Location = System::Drawing::Point(144, 223);
			this->lbl_siAlertas->Name = L"lbl_siAlertas";
			this->lbl_siAlertas->Size = System::Drawing::Size(20, 25);
			this->lbl_siAlertas->TabIndex = 3;
			this->lbl_siAlertas->Text = L"-";
			// 
			// lbl_noAlertas
			// 
			this->lbl_noAlertas->AutoSize = true;
			this->lbl_noAlertas->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_noAlertas->Location = System::Drawing::Point(65, 223);
			this->lbl_noAlertas->Name = L"lbl_noAlertas";
			this->lbl_noAlertas->Size = System::Drawing::Size(20, 25);
			this->lbl_noAlertas->TabIndex = 2;
			this->lbl_noAlertas->Text = L"-";
			// 
			// label_saludo
			// 
			this->label_saludo->AutoSize = true;
			this->label_saludo->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_saludo->Location = System::Drawing::Point(218, 157);
			this->label_saludo->Name = L"label_saludo";
			this->label_saludo->Size = System::Drawing::Size(314, 25);
			this->label_saludo->TabIndex = 1;
			this->label_saludo->Text = L"¡Bienvenido de vuelta a Inventrack!";
			// 
			// Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 451);
			this->Controls->Add(this->panel_info);
			this->Controls->Add(this->panel_menu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Proyecto final: Inventario y facturación";
			this->Load += gcnew System::EventHandler(this, &Menu::Menu_Load);
			this->panel_menu->ResumeLayout(false);
			this->panel_header->ResumeLayout(false);
			this->panel_header->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_alertas))->EndInit();
			this->panel_info->ResumeLayout(false);
			this->panel_info->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	//Función que permite abrir un formulario sin la necesidad de cerrar el principal, superponiéndose en un label
	template<class T>
	void ToOpen(T AddForm)
	{
		//Se verifica si ya hay un formulario agregado en el panel
		if (this->panel_info->Controls->Count > 0) 
		{
			//De ser así, se remueve antes de agregar el nuevo formulario, asegurando que solo un haya un formulario visible a la vez
			this->panel_info->Controls->Clear();
		}

		AddForm->TopLevel = false;
		AddForm->Dock = DockStyle::Fill; //Establecemos la propiedad del formulario en Fill
		AddForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; //Quitamos el borde del formulario, en caso de tener uno
		AddForm->Visible = true;

		this->panel_info->Controls->Add(AddForm);
		this->panel_info->AutoScroll = true;
		this->panel_info->Tag = AddForm;
		AddForm->Show(); //Se muestra el formulario
	}

	private: System::Void Menu_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargamos una imagen que simula un botón de alertas
		this->pB_alertas->Image = Image::FromFile("imagenmail.png");

		int totalAlertas = 0; // Con esta variable daremos una cuenta de cuántas alertas hay por verse 
		archivoProducto::notificarAlertas(totalAlertas, false);

		// Dependiendo si hay o no alertas, se le mostrará al usuario un mensaje informativo
		if (totalAlertas > 0) {
			lbl_noAlertas->Visible = false;
			lbl_siAlertas->Text = "Hay alertas relevantes que necesitan ser atendidas. \nPor favor, revisa la lista de alertas.";
		}
		else {
			lbl_siAlertas->Visible = false;
			lbl_noAlertas->Text = "No se han detectado situaciones críticas que requieran atención. \nTodos los productos se encuentran dentro de los límites establecidos.";
		}
	}
	private: System::Void btn_products_Click(System::Object^ sender, System::EventArgs^ e) {
		//Se abre el panel correspondiente a productos
		Inventrack::Productos^ prod = gcnew Inventrack::Productos();
		prod->username = userN;
		prod->role = role;
		this->ToOpen(prod);
		
		// Cambiar el color del botón a #1eafcf
		this->btn_products->BackColor = System::Drawing::Color::FromArgb(30, 175, 207);

		// Restablecer los otros botones a su color original
		this->btn_clients->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_providers->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_bills->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_settings->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_close->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
	}
	private: System::Void btn_clients_Click(System::Object^ sender, System::EventArgs^ e) {
		//Se abre el panel correspondiente a clientes
		this->ToOpen(gcnew Inventrack::Clientes);

		// Cambiar el color del botón a #1eafcf
		this->btn_clients->BackColor = System::Drawing::Color::FromArgb(30, 175, 207);

		// Restablecer los otros botones a su color original
		this->btn_products->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_providers->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_bills->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_settings->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_close->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
	}
	private: System::Void btn_providers_Click(System::Object^ sender, System::EventArgs^ e) {
		//Se abre el panel correspondiente a clientes
		this->ToOpen(gcnew Inventrack::Proveedores);

		// Cambiar el color del botón a #1eafcf
		this->btn_providers->BackColor = System::Drawing::Color::FromArgb(30, 175, 207);

		// Restablecer los otros botones a su color original
		this->btn_products->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_clients->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_bills->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_settings->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_close->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
	}
	private: System::Void btn_bills_Click(System::Object^ sender, System::EventArgs^ e) {
		//Se abre el panel correspondiente a factura
		Inventrack::Factura^ fact = gcnew Inventrack::Factura();
		fact->username = userN;
		fact->role = role;
		this->ToOpen(fact);

		// Cambiar el color del botón a #1eafcf
		this->btn_bills->BackColor = System::Drawing::Color::FromArgb(30, 175, 207);

		// Restablecer los otros botones a su color original
		this->btn_products->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_clients->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_providers->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_settings->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_close->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
	}
	private: System::Void btn_settings_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se abre el panel correspondiente a configuración
		Inventrack::Configuracion^ config = gcnew Inventrack::Configuracion();
		config->username = userN;
		config->role = role;
		this->ToOpen(config);

		// Cambiar el color del botón a #1eafcf
		this->btn_settings->BackColor = System::Drawing::Color::FromArgb(30, 175, 207);

		// Restablecer los otros botones a su color original
		this->btn_products->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_clients->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_providers->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_bills->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_close->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
	}
	private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e) {
		// Cambiar el color del botón a #1eafcf
		this->btn_close->BackColor = System::Drawing::Color::FromArgb(30, 175, 207);

		// Restablecer los otros botones a su color original
		this->btn_products->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_clients->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_providers->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_bills->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);
		this->btn_settings->BackColor = System::Drawing::Color::FromArgb(25, 146, 173);

		// Mostrar un MessageBox preguntando al usuario si quiere salir o no
		System::Windows::Forms::DialogResult result = MessageBox::Show(this, "¿Está seguro de que desea salir?", "Salir", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			// El usuario decidió salir; por tanto, se cierran todos los formularios que hayan quedado abiertos
			Application::Exit();
		}
		else {
			// El usuario decidió quedarse, no se hace nada
			return;
		}
	}
	private: System::Void pB_alertas_Click(System::Object^ sender, System::EventArgs^ e) {
		// Abrimos el formulario donde se mostrarán las alertas respecto a productos
		this->ToOpen(gcnew Inventrack::Alertas());
	}
	};
}