#pragma once
#include "Generar_factura.h"
#include "Reporte_factura.h"
#include "Seleccionar_unidadMedida.h"
#include "Frecuencia_clientes.h"
#include "Historial_factura.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Factura
	/// </summary>
	public ref class Factura : public System::Windows::Forms::Form
	{
	public:
		Factura(void)
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
		~Factura()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_headinfo;
	private: System::Windows::Forms::Label^ label_opcion;
	private: System::Windows::Forms::Label^ label_linea;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::Button^ btn_crearfac;
	private: System::Windows::Forms::Panel^ panel_crearf;
	private: System::Windows::Forms::PictureBox^ pb_flecha;
	private: System::Windows::Forms::Panel^ panel_reporte;
	private: System::Windows::Forms::Panel^ panel_r;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lbl_reporte;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pb_dobleflecha2;
	private: System::Windows::Forms::PictureBox^ pb_dobleflecha;
	private: System::Windows::Forms::Button^ btn_fclients;
	private: System::Windows::Forms::Button^ btn_comprod;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ lbl_compprod;
	private: System::Windows::Forms::PictureBox^ pb_generar;
	private: System::Windows::Forms::TextBox^ tb_fhasta;
	private: System::Windows::Forms::Label^ lbl_hasta;
	private: System::Windows::Forms::TextBox^ tb_fdesde;
	private: System::Windows::Forms::Label^ lbl_desde;
	private: System::Windows::Forms::Panel^ panel_fondohist;
	private: System::Windows::Forms::PictureBox^ pb_flecha2;
	private: System::Windows::Forms::Button^ btn_verhistorial;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::ComponentModel::IContainer^ components;
	// Declaramos variables que obtendrán la información del usuario que inició sesión
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
			this->panel_headinfo = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_opcion = (gcnew System::Windows::Forms::Label());
			this->label_linea = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_crearfac = (gcnew System::Windows::Forms::Button());
			this->panel_crearf = (gcnew System::Windows::Forms::Panel());
			this->pb_flecha = (gcnew System::Windows::Forms::PictureBox());
			this->panel_reporte = (gcnew System::Windows::Forms::Panel());
			this->pb_dobleflecha2 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_dobleflecha = (gcnew System::Windows::Forms::PictureBox());
			this->btn_fclients = (gcnew System::Windows::Forms::Button());
			this->btn_comprod = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lbl_compprod = (gcnew System::Windows::Forms::Label());
			this->pb_generar = (gcnew System::Windows::Forms::PictureBox());
			this->tb_fhasta = (gcnew System::Windows::Forms::TextBox());
			this->lbl_hasta = (gcnew System::Windows::Forms::Label());
			this->tb_fdesde = (gcnew System::Windows::Forms::TextBox());
			this->lbl_desde = (gcnew System::Windows::Forms::Label());
			this->panel_r = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lbl_reporte = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel_fondohist = (gcnew System::Windows::Forms::Panel());
			this->pb_flecha2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_verhistorial = (gcnew System::Windows::Forms::Button());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel_headinfo->SuspendLayout();
			this->panel_shadowing->SuspendLayout();
			this->panel_crearf->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_flecha))->BeginInit();
			this->panel_reporte->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_dobleflecha2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_dobleflecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_generar))->BeginInit();
			this->panel_r->SuspendLayout();
			this->panel_fondohist->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_flecha2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_headinfo
			// 
			this->panel_headinfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_headinfo->Controls->Add(this->label1);
			this->panel_headinfo->Controls->Add(this->label_opcion);
			this->panel_headinfo->Controls->Add(this->label_linea);
			this->panel_headinfo->Location = System::Drawing::Point(3, 3);
			this->panel_headinfo->Name = L"panel_headinfo";
			this->panel_headinfo->Size = System::Drawing::Size(695, 37);
			this->panel_headinfo->TabIndex = 1;
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
			// label_opcion
			// 
			this->label_opcion->AutoSize = true;
			this->label_opcion->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label_opcion->Location = System::Drawing::Point(10, 6);
			this->label_opcion->Name = L"label_opcion";
			this->label_opcion->Size = System::Drawing::Size(118, 19);
			this->label_opcion->TabIndex = 0;
			this->label_opcion->Text = L"Elija una opción...";
			// 
			// label_linea
			// 
			this->label_linea->AutoSize = true;
			this->label_linea->Location = System::Drawing::Point(3, 18);
			this->label_linea->Name = L"label_linea";
			this->label_linea->Size = System::Drawing::Size(205, 13);
			this->label_linea->TabIndex = 2;
			this->label_linea->Text = L"_________________________________";
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->panel_headinfo);
			this->panel_shadowing->Location = System::Drawing::Point(4, 5);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(701, 44);
			this->panel_shadowing->TabIndex = 5;
			// 
			// btn_crearfac
			// 
			this->btn_crearfac->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_crearfac->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_crearfac->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_crearfac->Location = System::Drawing::Point(1, 1);
			this->btn_crearfac->Name = L"btn_crearfac";
			this->btn_crearfac->Size = System::Drawing::Size(697, 49);
			this->btn_crearfac->TabIndex = 2;
			this->btn_crearfac->Text = L"   Crear factura";
			this->btn_crearfac->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_crearfac->UseVisualStyleBackColor = false;
			this->btn_crearfac->Click += gcnew System::EventHandler(this, &Factura::btn_crearfac_Click);
			// 
			// panel_crearf
			// 
			this->panel_crearf->BackColor = System::Drawing::Color::LightGray;
			this->panel_crearf->Controls->Add(this->pb_flecha);
			this->panel_crearf->Controls->Add(this->btn_crearfac);
			this->panel_crearf->Location = System::Drawing::Point(4, 76);
			this->panel_crearf->Name = L"panel_crearf";
			this->panel_crearf->Size = System::Drawing::Size(701, 52);
			this->panel_crearf->TabIndex = 6;
			// 
			// pb_flecha
			// 
			this->pb_flecha->Location = System::Drawing::Point(106, 9);
			this->pb_flecha->Name = L"pb_flecha";
			this->pb_flecha->Size = System::Drawing::Size(28, 33);
			this->pb_flecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pb_flecha->TabIndex = 3;
			this->pb_flecha->TabStop = false;
			// 
			// panel_reporte
			// 
			this->panel_reporte->BackColor = System::Drawing::Color::LightGray;
			this->panel_reporte->Controls->Add(this->pb_dobleflecha2);
			this->panel_reporte->Controls->Add(this->pb_dobleflecha);
			this->panel_reporte->Controls->Add(this->btn_fclients);
			this->panel_reporte->Controls->Add(this->btn_comprod);
			this->panel_reporte->Controls->Add(this->label6);
			this->panel_reporte->Controls->Add(this->lbl_compprod);
			this->panel_reporte->Controls->Add(this->pb_generar);
			this->panel_reporte->Controls->Add(this->tb_fhasta);
			this->panel_reporte->Controls->Add(this->lbl_hasta);
			this->panel_reporte->Controls->Add(this->tb_fdesde);
			this->panel_reporte->Controls->Add(this->lbl_desde);
			this->panel_reporte->Controls->Add(this->panel_r);
			this->panel_reporte->Location = System::Drawing::Point(4, 156);
			this->panel_reporte->Name = L"panel_reporte";
			this->panel_reporte->Size = System::Drawing::Size(701, 196);
			this->panel_reporte->TabIndex = 7;
			// 
			// pb_dobleflecha2
			// 
			this->pb_dobleflecha2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->pb_dobleflecha2->Location = System::Drawing::Point(161, 157);
			this->pb_dobleflecha2->Name = L"pb_dobleflecha2";
			this->pb_dobleflecha2->Size = System::Drawing::Size(26, 20);
			this->pb_dobleflecha2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pb_dobleflecha2->TabIndex = 28;
			this->pb_dobleflecha2->TabStop = false;
			// 
			// pb_dobleflecha
			// 
			this->pb_dobleflecha->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->pb_dobleflecha->Location = System::Drawing::Point(277, 123);
			this->pb_dobleflecha->Name = L"pb_dobleflecha";
			this->pb_dobleflecha->Size = System::Drawing::Size(26, 20);
			this->pb_dobleflecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pb_dobleflecha->TabIndex = 27;
			this->pb_dobleflecha->TabStop = false;
			// 
			// btn_fclients
			// 
			this->btn_fclients->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_fclients->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_fclients->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8, System::Drawing::FontStyle::Bold));
			this->btn_fclients->Location = System::Drawing::Point(9, 153);
			this->btn_fclients->Name = L"btn_fclients";
			this->btn_fclients->Size = System::Drawing::Size(374, 28);
			this->btn_fclients->TabIndex = 26;
			this->btn_fclients->Text = L"   Ver frecuencia de clientes";
			this->btn_fclients->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_fclients->UseVisualStyleBackColor = false;
			this->btn_fclients->Click += gcnew System::EventHandler(this, &Factura::btn_fclients_Click);
			// 
			// btn_comprod
			// 
			this->btn_comprod->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_comprod->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_comprod->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8, System::Drawing::FontStyle::Bold));
			this->btn_comprod->Location = System::Drawing::Point(9, 119);
			this->btn_comprod->Name = L"btn_comprod";
			this->btn_comprod->Size = System::Drawing::Size(374, 28);
			this->btn_comprod->TabIndex = 25;
			this->btn_comprod->Text = L"   Ver comportamiento de los productos vendidos";
			this->btn_comprod->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_comprod->UseVisualStyleBackColor = false;
			this->btn_comprod->Click += gcnew System::EventHandler(this, &Factura::btn_comprod_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(22, 146);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 15);
			this->label6->TabIndex = 24;
			// 
			// lbl_compprod
			// 
			this->lbl_compprod->AutoSize = true;
			this->lbl_compprod->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_compprod->Location = System::Drawing::Point(22, 119);
			this->lbl_compprod->Name = L"lbl_compprod";
			this->lbl_compprod->Size = System::Drawing::Size(0, 15);
			this->lbl_compprod->TabIndex = 23;
			// 
			// pb_generar
			// 
			this->pb_generar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pb_generar->Location = System::Drawing::Point(304, 69);
			this->pb_generar->Name = L"pb_generar";
			this->pb_generar->Size = System::Drawing::Size(38, 29);
			this->pb_generar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pb_generar->TabIndex = 22;
			this->pb_generar->TabStop = false;
			this->pb_generar->Click += gcnew System::EventHandler(this, &Factura::pb_generar_Click);
			// 
			// tb_fhasta
			// 
			this->tb_fhasta->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_fhasta->Location = System::Drawing::Point(174, 74);
			this->tb_fhasta->Name = L"tb_fhasta";
			this->tb_fhasta->Size = System::Drawing::Size(107, 22);
			this->tb_fhasta->TabIndex = 21;
			this->tb_fhasta->Enter += gcnew System::EventHandler(this, &Factura::tb_fhasta_Enter);
			this->tb_fhasta->Leave += gcnew System::EventHandler(this, &Factura::tb_fhasta_Leave);
			// 
			// lbl_hasta
			// 
			this->lbl_hasta->AutoSize = true;
			this->lbl_hasta->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_hasta->Location = System::Drawing::Point(171, 56);
			this->lbl_hasta->Name = L"lbl_hasta";
			this->lbl_hasta->Size = System::Drawing::Size(37, 15);
			this->lbl_hasta->TabIndex = 20;
			this->lbl_hasta->Text = L"Hasta";
			// 
			// tb_fdesde
			// 
			this->tb_fdesde->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_fdesde->Location = System::Drawing::Point(17, 74);
			this->tb_fdesde->Name = L"tb_fdesde";
			this->tb_fdesde->Size = System::Drawing::Size(107, 22);
			this->tb_fdesde->TabIndex = 19;
			this->tb_fdesde->Enter += gcnew System::EventHandler(this, &Factura::tb_fdesde_Enter);
			this->tb_fdesde->Leave += gcnew System::EventHandler(this, &Factura::tb_fdesde_Leave);
			// 
			// lbl_desde
			// 
			this->lbl_desde->AutoSize = true;
			this->lbl_desde->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_desde->Location = System::Drawing::Point(14, 56);
			this->lbl_desde->Name = L"lbl_desde";
			this->lbl_desde->Size = System::Drawing::Size(40, 15);
			this->lbl_desde->TabIndex = 18;
			this->lbl_desde->Text = L"Desde";
			// 
			// panel_r
			// 
			this->panel_r->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_r->Controls->Add(this->label3);
			this->panel_r->Controls->Add(this->lbl_reporte);
			this->panel_r->Controls->Add(this->label5);
			this->panel_r->Location = System::Drawing::Point(3, 3);
			this->panel_r->Name = L"panel_r";
			this->panel_r->Size = System::Drawing::Size(695, 37);
			this->panel_r->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(10, 306);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 19);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Registrar productos";
			// 
			// lbl_reporte
			// 
			this->lbl_reporte->AutoSize = true;
			this->lbl_reporte->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_reporte->Location = System::Drawing::Point(10, 9);
			this->lbl_reporte->Name = L"lbl_reporte";
			this->lbl_reporte->Size = System::Drawing::Size(131, 19);
			this->lbl_reporte->TabIndex = 0;
			this->lbl_reporte->Text = L"Reporte de facturas";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 2;
			// 
			// panel_fondohist
			// 
			this->panel_fondohist->BackColor = System::Drawing::Color::LightGray;
			this->panel_fondohist->Controls->Add(this->pb_flecha2);
			this->panel_fondohist->Controls->Add(this->btn_verhistorial);
			this->panel_fondohist->Location = System::Drawing::Point(4, 375);
			this->panel_fondohist->Name = L"panel_fondohist";
			this->panel_fondohist->Size = System::Drawing::Size(701, 52);
			this->panel_fondohist->TabIndex = 9;
			// 
			// pb_flecha2
			// 
			this->pb_flecha2->Location = System::Drawing::Point(174, 9);
			this->pb_flecha2->Name = L"pb_flecha2";
			this->pb_flecha2->Size = System::Drawing::Size(28, 33);
			this->pb_flecha2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pb_flecha2->TabIndex = 3;
			this->pb_flecha2->TabStop = false;
			// 
			// btn_verhistorial
			// 
			this->btn_verhistorial->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_verhistorial->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_verhistorial->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_verhistorial->Location = System::Drawing::Point(1, 1);
			this->btn_verhistorial->Name = L"btn_verhistorial";
			this->btn_verhistorial->Size = System::Drawing::Size(697, 49);
			this->btn_verhistorial->TabIndex = 2;
			this->btn_verhistorial->Text = L"   Ver historial de facturas";
			this->btn_verhistorial->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_verhistorial->UseVisualStyleBackColor = false;
			this->btn_verhistorial->Click += gcnew System::EventHandler(this, &Factura::btn_verhistorial_Click);
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Factura
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(717, 451);
			this->Controls->Add(this->panel_fondohist);
			this->Controls->Add(this->panel_reporte);
			this->Controls->Add(this->panel_shadowing);
			this->Controls->Add(this->panel_crearf);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Factura";
			this->Text = L"Factura";
			this->Load += gcnew System::EventHandler(this, &Factura::Factura_Load);
			this->panel_headinfo->ResumeLayout(false);
			this->panel_headinfo->PerformLayout();
			this->panel_shadowing->ResumeLayout(false);
			this->panel_crearf->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_flecha))->EndInit();
			this->panel_reporte->ResumeLayout(false);
			this->panel_reporte->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_dobleflecha2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_dobleflecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_generar))->EndInit();
			this->panel_r->ResumeLayout(false);
			this->panel_r->PerformLayout();
			this->panel_fondohist->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_flecha2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Factura_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se cargan los placeholders de las fechas "desde" y "hasta"
		this->tb_fdesde->Text = date_structure;
		this->tb_fhasta->Text = date_structure;

		// Se carga una imagen que simula una flecha en crear factura
		this->pb_flecha->Image = Image::FromFile("flechaclic.png");
		this->pb_flecha2->Image = Image::FromFile("flechaclic.png");

		// Se carga una imagen que simula una flecha de ingreso en reporte de factura
		this->pb_generar->Image = Image::FromFile("botongenerar.png");
		
		// Se carga una imagen que simula una doble flecha de ingreso en reporte de factura
		this->pb_dobleflecha->Image = Image::FromFile("dobleflechaclic.png");
		this->pb_dobleflecha2->Image = Image::FromFile("dobleflechaclic.png");
	}
	// Por motivos de mayor entendimiento al registro, se darán indicaciones adicionales con texto como placeholders
	private: System::String^ date_structure = "dd/mm/aaaa";
	private: System::Void tb_fdesde_Enter(System::Object^ sender, System::EventArgs^ e) {
		// Borra el texto predeterminado cuando el control TextBox obtiene el foco
		if (tb_fdesde->Text == date_structure) {
			tb_fdesde->Text = "";
			tb_fdesde->ForeColor = SystemColors::WindowText;
			tb_fdesde->ReadOnly = false;
			// Al obtener el foco cambiamos la fuente de texto a predeterminado
			tb_fdesde->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
		}
	}
	private: System::Void tb_fdesde_Leave(System::Object^ sender, System::EventArgs^ e) {
		// Restaura el texto predeterminado si el usuario no ingresó nada
		if (this->tb_fdesde->Text == "") {
			this->tb_fdesde->Text = date_structure;
			this->tb_fdesde->ForeColor = SystemColors::InactiveCaption;
			tb_fdesde->ReadOnly = true;
			// Al momento de no interactuar con el textbox, se usa una fuente de texto personalizada con estilo itálico
			tb_fdesde->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic));
		}
	}
	private: System::Void tb_fhasta_Enter(System::Object^ sender, System::EventArgs^ e) {
		// Borra el texto predeterminado cuando el control TextBox obtiene el foco
		if (tb_fhasta->Text == date_structure) {
			tb_fhasta->Text = "";
			tb_fhasta->ForeColor = SystemColors::WindowText;
			tb_fhasta->ReadOnly = false;
			// Al obtener el foco cambiamos la fuente de texto a predeterminado
			tb_fhasta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
		}
	}
	private: System::Void tb_fhasta_Leave(System::Object^ sender, System::EventArgs^ e) {
		// Restaura el texto predeterminado si el usuario no ingresó nada
		if (this->tb_fhasta->Text == "") {
			this->tb_fhasta->Text = date_structure;
			this->tb_fhasta->ForeColor = SystemColors::InactiveCaption;
			tb_fhasta->ReadOnly = true;
			// Al momento de no interactuar con el textbox, se usa una fuente de texto personalizada con estilo itálico
			tb_fhasta->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic));
		}
	}
	private: System::Void btn_crearfac_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo factura" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Creamos una nueva instancia del formulario de "Generar_factura.h"
		Inventrack::Generar_factura^ Generar = gcnew Inventrack::Generar_factura();
		Generar->username = username;
		Generar->Show();
	}
	private: System::Void pb_generar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo factura" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		int error = 0;
		// Redactamos el mensaje de error en caso de que la fecha "desde" sea mayor que la fecha "hasta"
		String^ invalidRange = "La fecha de inicio no puede ser mayor que la fecha de fin.";

		/* Validamos si los TextBoxes no están vacíos, si la fecha está en un formato correcto y...
		...las fechas ingresadas tienen concordancia en su rango*/
		validate::isDate_correct(tb_fdesde, errorProvider, false, error);
		validate::isDate_correct(tb_fhasta, errorProvider, false, error);
		
		// Verificamos si han habido errores de entrada por el momento
		if (error > 0) {
			return;
		}

		validate::is_toDate_lessthan(tb_fdesde, tb_fhasta, errorProvider, invalidRange, error);

		// Verificamos por última vez si la entrada tuvo errores en el proceso
		if (error > 0) {
			return;
		}

		string fdesde = conversion::to_stdstring(tb_fdesde->Text);
		string fhasta = conversion::to_stdstring(tb_fhasta->Text);

		// Cambiamos los valores ingresados de System::String a std::string
		archivoFactura::registrar_reporteFactura(fdesde, fhasta);
		// Creamos una nueva instancia del formulario de "Reporte_factura.h"
		Inventrack::Reporte_factura^ Reporte = gcnew Inventrack::Reporte_factura();
		Reporte->Show();
	}
	private: System::Void btn_comprod_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo factura" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Creamos una nueva instancia del formulario de selección de unidad
		Inventrack::Seleccionar_unidadMedida^ select = gcnew Inventrack::Seleccionar_unidadMedida();
		select->ShowDialog();
	}
	private: System::Void btn_fclients_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo factura" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Creamos una nueva instancia del formulario de "Frecuencia_clientes.h"
		Inventrack::Frecuencia_clientes^ Fclientes = gcnew Inventrack::Frecuencia_clientes();
		Fclientes->Show();
	}
	private: System::Void btn_verhistorial_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo factura" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Creamos una nueva instancia del formulario de "Historial_factura.h"
		Inventrack::Historial_factura^ Historial = gcnew Inventrack::Historial_factura();
		Historial->Show();
	}
	};
}