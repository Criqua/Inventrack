#pragma once
#include "SystemString_toStdString.h"
#include "Validaciones.h"
#include "clientes/archivarClientes.h"
#include "factura/auto_codefact.h"
#include "productos/archivarProductos.h"
#include "config/archivarConfiguracion.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de Generar_factura
	/// </summary>
	public ref class Generar_factura : public System::Windows::Forms::Form
	{
	public:
		Generar_factura(void)
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
		~Generar_factura()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel5;
	protected:
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ lbl_historial;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel_fondo;
	private: System::Windows::Forms::TextBox^ tb_cant;
	private: System::Windows::Forms::Label^ lbl_cant;
	private: System::Windows::Forms::TextBox^ tb_discount;
	private: System::Windows::Forms::Label^ lbl_discount;
	private: System::Windows::Forms::Label^ lbl_busqueda;

	private: System::Windows::Forms::Label^ lbl_vendedor;
	private: System::Windows::Forms::ComboBox^ cb_formapago;
	private: System::Windows::Forms::Label^ lbl_payment;
	private: System::Windows::Forms::ComboBox^ cb_client;
	private: System::Windows::Forms::Label^ lbl_client;
	private: System::Windows::Forms::Button^ btn_adicionar;
	private: System::Windows::Forms::Button^ btn_generarfactura;
	private: System::Windows::Forms::DataGridView^ dgv_prods;
	private: System::Windows::Forms::TextBox^ tb_busqueda;
	private: System::Windows::Forms::Label^ lbl_uMeasure;
	private: System::Windows::Forms::Label^ lbl_u;
	private: System::Windows::Forms::Label^ lbl_pUnit;
	private: System::Windows::Forms::Label^ lbl_pU;
	private: System::Windows::Forms::Label^ lbl_descripcionprod;
	private: System::Windows::Forms::Label^ lbl_desc;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lbl_dirempresa;
	private: System::Windows::Forms::Label^ lbl_nomempresa;
	private: System::Windows::Forms::Label^ lbl_numfactura;
	private: System::Windows::Forms::Label^ lbl_telempresa;
	private: System::Windows::Forms::Label^ lbl_correoempresa;
	private: System::Windows::Forms::Label^ lbl_fecha;
	private: System::Windows::Forms::Label^ lbl_hora;
	private: System::Windows::Forms::PictureBox^ pictureBox_buscar;
	private: System::Windows::Forms::TextBox^ tb_subtotal;
	private: System::Windows::Forms::Label^ lbl_subtotal;
	private: System::Windows::Forms::Panel^ panel_pago;
	private: System::Windows::Forms::TextBox^ tb_totalpagar;
	private: System::Windows::Forms::Label^ lbl_total_pagar;
	private: System::Windows::Forms::Label^ lbl_totaldevuelto;
	private: System::Windows::Forms::TextBox^ tb_totalpagado;
	private: System::Windows::Forms::Label^ lbl_totalpagado;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::Windows::Forms::Label^ lbl_eX;
	private: System::Windows::Forms::TextBox^ tb_existCan;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Producto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Precio_unit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Descuento;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Total;
	private: System::Windows::Forms::TextBox^ tb_totaldevuelto;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ cb_vendedor;
	private: System::Windows::Forms::TextBox^ tb_masIVA;

	private: System::Windows::Forms::Label^ lbl_masIVA;
	public: String^ nEmp = "";
	public: String^ tEmp = "";
	public: String^ eEmp = "";
	public: String^ dEmp = "";
	// Declaramos variables que obtendrán la información del usuario que inició sesión
	public: String^ username = "";
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbl_historial = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel_fondo = (gcnew System::Windows::Forms::Panel());
			this->cb_vendedor = (gcnew System::Windows::Forms::Label());
			this->tb_existCan = (gcnew System::Windows::Forms::TextBox());
			this->lbl_eX = (gcnew System::Windows::Forms::Label());
			this->pictureBox_buscar = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_numfactura = (gcnew System::Windows::Forms::Label());
			this->lbl_telempresa = (gcnew System::Windows::Forms::Label());
			this->lbl_correoempresa = (gcnew System::Windows::Forms::Label());
			this->lbl_fecha = (gcnew System::Windows::Forms::Label());
			this->lbl_hora = (gcnew System::Windows::Forms::Label());
			this->lbl_dirempresa = (gcnew System::Windows::Forms::Label());
			this->lbl_nomempresa = (gcnew System::Windows::Forms::Label());
			this->lbl_uMeasure = (gcnew System::Windows::Forms::Label());
			this->lbl_u = (gcnew System::Windows::Forms::Label());
			this->lbl_pUnit = (gcnew System::Windows::Forms::Label());
			this->lbl_pU = (gcnew System::Windows::Forms::Label());
			this->lbl_descripcionprod = (gcnew System::Windows::Forms::Label());
			this->lbl_desc = (gcnew System::Windows::Forms::Label());
			this->tb_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->dgv_prods = (gcnew System::Windows::Forms::DataGridView());
			this->Producto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Precio_unit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Descuento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Total = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btn_generarfactura = (gcnew System::Windows::Forms::Button());
			this->btn_adicionar = (gcnew System::Windows::Forms::Button());
			this->tb_cant = (gcnew System::Windows::Forms::TextBox());
			this->lbl_cant = (gcnew System::Windows::Forms::Label());
			this->tb_discount = (gcnew System::Windows::Forms::TextBox());
			this->lbl_discount = (gcnew System::Windows::Forms::Label());
			this->lbl_busqueda = (gcnew System::Windows::Forms::Label());
			this->lbl_vendedor = (gcnew System::Windows::Forms::Label());
			this->cb_formapago = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_payment = (gcnew System::Windows::Forms::Label());
			this->cb_client = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_client = (gcnew System::Windows::Forms::Label());
			this->panel_pago = (gcnew System::Windows::Forms::Panel());
			this->tb_masIVA = (gcnew System::Windows::Forms::TextBox());
			this->lbl_masIVA = (gcnew System::Windows::Forms::Label());
			this->tb_totaldevuelto = (gcnew System::Windows::Forms::TextBox());
			this->lbl_totaldevuelto = (gcnew System::Windows::Forms::Label());
			this->tb_totalpagado = (gcnew System::Windows::Forms::TextBox());
			this->lbl_totalpagado = (gcnew System::Windows::Forms::Label());
			this->tb_subtotal = (gcnew System::Windows::Forms::TextBox());
			this->tb_totalpagar = (gcnew System::Windows::Forms::TextBox());
			this->lbl_subtotal = (gcnew System::Windows::Forms::Label());
			this->lbl_total_pagar = (gcnew System::Windows::Forms::Label());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel5->SuspendLayout();
			this->panel_fondo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_prods))->BeginInit();
			this->panel_pago->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->lbl_historial);
			this->panel5->Controls->Add(this->label13);
			this->panel5->Location = System::Drawing::Point(7, 7);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(863, 37);
			this->panel5->TabIndex = 2;
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
			// lbl_historial
			// 
			this->lbl_historial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_historial->AutoSize = true;
			this->lbl_historial->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_historial->Location = System::Drawing::Point(10, 7);
			this->lbl_historial->Name = L"lbl_historial";
			this->lbl_historial->Size = System::Drawing::Size(137, 20);
			this->lbl_historial->TabIndex = 0;
			this->lbl_historial->Text = L"Datos de la factura";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 2;
			// 
			// panel_fondo
			// 
			this->panel_fondo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_fondo->BackColor = System::Drawing::SystemColors::MenuBar;
			this->panel_fondo->Controls->Add(this->cb_vendedor);
			this->panel_fondo->Controls->Add(this->tb_existCan);
			this->panel_fondo->Controls->Add(this->lbl_eX);
			this->panel_fondo->Controls->Add(this->pictureBox_buscar);
			this->panel_fondo->Controls->Add(this->panel1);
			this->panel_fondo->Controls->Add(this->lbl_uMeasure);
			this->panel_fondo->Controls->Add(this->lbl_u);
			this->panel_fondo->Controls->Add(this->lbl_pUnit);
			this->panel_fondo->Controls->Add(this->lbl_pU);
			this->panel_fondo->Controls->Add(this->lbl_descripcionprod);
			this->panel_fondo->Controls->Add(this->lbl_desc);
			this->panel_fondo->Controls->Add(this->tb_busqueda);
			this->panel_fondo->Controls->Add(this->dgv_prods);
			this->panel_fondo->Controls->Add(this->btn_generarfactura);
			this->panel_fondo->Controls->Add(this->btn_adicionar);
			this->panel_fondo->Controls->Add(this->tb_cant);
			this->panel_fondo->Controls->Add(this->lbl_cant);
			this->panel_fondo->Controls->Add(this->tb_discount);
			this->panel_fondo->Controls->Add(this->lbl_discount);
			this->panel_fondo->Controls->Add(this->lbl_busqueda);
			this->panel_fondo->Controls->Add(this->lbl_vendedor);
			this->panel_fondo->Controls->Add(this->cb_formapago);
			this->panel_fondo->Controls->Add(this->lbl_payment);
			this->panel_fondo->Controls->Add(this->cb_client);
			this->panel_fondo->Controls->Add(this->lbl_client);
			this->panel_fondo->Controls->Add(this->panel_pago);
			this->panel_fondo->Location = System::Drawing::Point(4, 4);
			this->panel_fondo->Name = L"panel_fondo";
			this->panel_fondo->Size = System::Drawing::Size(869, 702);
			this->panel_fondo->TabIndex = 10;
			// 
			// cb_vendedor
			// 
			this->cb_vendedor->AutoSize = true;
			this->cb_vendedor->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_vendedor->Location = System::Drawing::Point(623, 123);
			this->cb_vendedor->Name = L"cb_vendedor";
			this->cb_vendedor->Size = System::Drawing::Size(13, 17);
			this->cb_vendedor->TabIndex = 37;
			this->cb_vendedor->Text = L"-";
			// 
			// tb_existCan
			// 
			this->tb_existCan->Location = System::Drawing::Point(17, 351);
			this->tb_existCan->Name = L"tb_existCan";
			this->tb_existCan->Size = System::Drawing::Size(79, 20);
			this->tb_existCan->TabIndex = 36;
			this->tb_existCan->Visible = false;
			// 
			// lbl_eX
			// 
			this->lbl_eX->AutoSize = true;
			this->lbl_eX->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_eX->Location = System::Drawing::Point(14, 331);
			this->lbl_eX->Name = L"lbl_eX";
			this->lbl_eX->Size = System::Drawing::Size(124, 17);
			this->lbl_eX->TabIndex = 34;
			this->lbl_eX->Text = L"Cantidad existente:";
			this->lbl_eX->Visible = false;
			// 
			// pictureBox_buscar
			// 
			this->pictureBox_buscar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox_buscar->Location = System::Drawing::Point(168, 221);
			this->pictureBox_buscar->Name = L"pictureBox_buscar";
			this->pictureBox_buscar->Size = System::Drawing::Size(18, 18);
			this->pictureBox_buscar->TabIndex = 30;
			this->pictureBox_buscar->TabStop = false;
			this->pictureBox_buscar->Click += gcnew System::EventHandler(this, &Generar_factura::pictureBox_buscar_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->lbl_numfactura);
			this->panel1->Controls->Add(this->lbl_telempresa);
			this->panel1->Controls->Add(this->lbl_correoempresa);
			this->panel1->Controls->Add(this->lbl_fecha);
			this->panel1->Controls->Add(this->lbl_hora);
			this->panel1->Controls->Add(this->lbl_dirempresa);
			this->panel1->Controls->Add(this->lbl_nomempresa);
			this->panel1->Location = System::Drawing::Point(17, 47);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(500, 138);
			this->panel1->TabIndex = 29;
			// 
			// lbl_numfactura
			// 
			this->lbl_numfactura->AutoSize = true;
			this->lbl_numfactura->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_numfactura->Location = System::Drawing::Point(427, 6);
			this->lbl_numfactura->Name = L"lbl_numfactura";
			this->lbl_numfactura->Size = System::Drawing::Size(57, 17);
			this->lbl_numfactura->TabIndex = 9;
			this->lbl_numfactura->Text = L"No. Fact";
			// 
			// lbl_telempresa
			// 
			this->lbl_telempresa->AutoSize = true;
			this->lbl_telempresa->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_telempresa->Location = System::Drawing::Point(176, 78);
			this->lbl_telempresa->Name = L"lbl_telempresa";
			this->lbl_telempresa->Size = System::Drawing::Size(148, 17);
			this->lbl_telempresa->TabIndex = 8;
			this->lbl_telempresa->Text = L"Teléfono de la empresa";
			// 
			// lbl_correoempresa
			// 
			this->lbl_correoempresa->AutoSize = true;
			this->lbl_correoempresa->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_correoempresa->Location = System::Drawing::Point(176, 55);
			this->lbl_correoempresa->Name = L"lbl_correoempresa";
			this->lbl_correoempresa->Size = System::Drawing::Size(138, 17);
			this->lbl_correoempresa->TabIndex = 7;
			this->lbl_correoempresa->Text = L"Correo de la empresa";
			// 
			// lbl_fecha
			// 
			this->lbl_fecha->AutoSize = true;
			this->lbl_fecha->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_fecha->Location = System::Drawing::Point(13, 103);
			this->lbl_fecha->Name = L"lbl_fecha";
			this->lbl_fecha->Size = System::Drawing::Size(112, 17);
			this->lbl_fecha->TabIndex = 6;
			this->lbl_fecha->Text = L"Fecha de emisión";
			// 
			// lbl_hora
			// 
			this->lbl_hora->AutoSize = true;
			this->lbl_hora->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_hora->Location = System::Drawing::Point(13, 78);
			this->lbl_hora->Name = L"lbl_hora";
			this->lbl_hora->Size = System::Drawing::Size(38, 17);
			this->lbl_hora->TabIndex = 5;
			this->lbl_hora->Text = L"Hora";
			// 
			// lbl_dirempresa
			// 
			this->lbl_dirempresa->AutoSize = true;
			this->lbl_dirempresa->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_dirempresa->Location = System::Drawing::Point(176, 31);
			this->lbl_dirempresa->Name = L"lbl_dirempresa";
			this->lbl_dirempresa->Size = System::Drawing::Size(152, 17);
			this->lbl_dirempresa->TabIndex = 4;
			this->lbl_dirempresa->Text = L"Dirección de la empresa";
			// 
			// lbl_nomempresa
			// 
			this->lbl_nomempresa->AutoSize = true;
			this->lbl_nomempresa->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nomempresa->Location = System::Drawing::Point(176, 6);
			this->lbl_nomempresa->Name = L"lbl_nomempresa";
			this->lbl_nomempresa->Size = System::Drawing::Size(147, 17);
			this->lbl_nomempresa->TabIndex = 3;
			this->lbl_nomempresa->Text = L"Nombre de la empresa";
			// 
			// lbl_uMeasure
			// 
			this->lbl_uMeasure->AutoSize = true;
			this->lbl_uMeasure->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_uMeasure->Location = System::Drawing::Point(151, 278);
			this->lbl_uMeasure->Name = L"lbl_uMeasure";
			this->lbl_uMeasure->Size = System::Drawing::Size(13, 17);
			this->lbl_uMeasure->TabIndex = 28;
			this->lbl_uMeasure->Text = L"-";
			// 
			// lbl_u
			// 
			this->lbl_u->AutoSize = true;
			this->lbl_u->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_u->Location = System::Drawing::Point(14, 278);
			this->lbl_u->Name = L"lbl_u";
			this->lbl_u->Size = System::Drawing::Size(122, 17);
			this->lbl_u->TabIndex = 27;
			this->lbl_u->Text = L"Unidad de medida:";
			// 
			// lbl_pUnit
			// 
			this->lbl_pUnit->AutoSize = true;
			this->lbl_pUnit->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_pUnit->Location = System::Drawing::Point(151, 304);
			this->lbl_pUnit->Name = L"lbl_pUnit";
			this->lbl_pUnit->Size = System::Drawing::Size(13, 17);
			this->lbl_pUnit->TabIndex = 26;
			this->lbl_pUnit->Text = L"-";
			// 
			// lbl_pU
			// 
			this->lbl_pU->AutoSize = true;
			this->lbl_pU->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_pU->Location = System::Drawing::Point(14, 304);
			this->lbl_pU->Name = L"lbl_pU";
			this->lbl_pU->Size = System::Drawing::Size(126, 17);
			this->lbl_pU->TabIndex = 25;
			this->lbl_pU->Text = L"Precio unitario (C$):";
			// 
			// lbl_descripcionprod
			// 
			this->lbl_descripcionprod->AutoSize = true;
			this->lbl_descripcionprod->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_descripcionprod->Location = System::Drawing::Point(109, 252);
			this->lbl_descripcionprod->Name = L"lbl_descripcionprod";
			this->lbl_descripcionprod->Size = System::Drawing::Size(13, 17);
			this->lbl_descripcionprod->TabIndex = 24;
			this->lbl_descripcionprod->Text = L"-";
			// 
			// lbl_desc
			// 
			this->lbl_desc->AutoSize = true;
			this->lbl_desc->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_desc->Location = System::Drawing::Point(14, 252);
			this->lbl_desc->Name = L"lbl_desc";
			this->lbl_desc->Size = System::Drawing::Size(80, 17);
			this->lbl_desc->TabIndex = 23;
			this->lbl_desc->Text = L"Descripción:";
			// 
			// tb_busqueda
			// 
			this->tb_busqueda->Location = System::Drawing::Point(17, 220);
			this->tb_busqueda->Name = L"tb_busqueda";
			this->tb_busqueda->Size = System::Drawing::Size(170, 20);
			this->tb_busqueda->TabIndex = 22;
			// 
			// dgv_prods
			// 
			this->dgv_prods->AllowUserToAddRows = false;
			this->dgv_prods->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_prods->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgv_prods->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_prods->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Producto, this->Cantidad,
					this->Precio_unit, this->Descuento, this->Total
			});
			this->dgv_prods->Location = System::Drawing::Point(165, 335);
			this->dgv_prods->Name = L"dgv_prods";
			this->dgv_prods->Size = System::Drawing::Size(544, 221);
			this->dgv_prods->TabIndex = 21;
			// 
			// Producto
			// 
			this->Producto->HeaderText = L"Producto";
			this->Producto->Name = L"Producto";
			// 
			// Cantidad
			// 
			this->Cantidad->HeaderText = L"Cantidad";
			this->Cantidad->Name = L"Cantidad";
			// 
			// Precio_unit
			// 
			this->Precio_unit->HeaderText = L"Precio unit.";
			this->Precio_unit->Name = L"Precio_unit";
			// 
			// Descuento
			// 
			this->Descuento->HeaderText = L"Descuento";
			this->Descuento->Name = L"Descuento";
			// 
			// Total
			// 
			this->Total->HeaderText = L"Total";
			this->Total->Name = L"Total";
			// 
			// btn_generarfactura
			// 
			this->btn_generarfactura->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(146)), static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_generarfactura->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_generarfactura->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_generarfactura->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_generarfactura->ForeColor = System::Drawing::Color::White;
			this->btn_generarfactura->Location = System::Drawing::Point(347, 650);
			this->btn_generarfactura->Name = L"btn_generarfactura";
			this->btn_generarfactura->Size = System::Drawing::Size(181, 33);
			this->btn_generarfactura->TabIndex = 20;
			this->btn_generarfactura->Text = L"Generar factura";
			this->btn_generarfactura->UseVisualStyleBackColor = false;
			this->btn_generarfactura->Click += gcnew System::EventHandler(this, &Generar_factura::btn_generarfactura_Click);
			// 
			// btn_adicionar
			// 
			this->btn_adicionar->BackColor = System::Drawing::Color::DimGray;
			this->btn_adicionar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_adicionar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_adicionar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_adicionar->ForeColor = System::Drawing::Color::White;
			this->btn_adicionar->Location = System::Drawing::Point(386, 292);
			this->btn_adicionar->Name = L"btn_adicionar";
			this->btn_adicionar->Size = System::Drawing::Size(102, 33);
			this->btn_adicionar->TabIndex = 19;
			this->btn_adicionar->Text = L"Adicionar";
			this->btn_adicionar->UseVisualStyleBackColor = false;
			this->btn_adicionar->Click += gcnew System::EventHandler(this, &Generar_factura::btn_adicionar_Click);
			// 
			// tb_cant
			// 
			this->tb_cant->Location = System::Drawing::Point(236, 219);
			this->tb_cant->Name = L"tb_cant";
			this->tb_cant->Size = System::Drawing::Size(79, 20);
			this->tb_cant->TabIndex = 15;
			// 
			// lbl_cant
			// 
			this->lbl_cant->AutoSize = true;
			this->lbl_cant->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_cant->Location = System::Drawing::Point(233, 200);
			this->lbl_cant->Name = L"lbl_cant";
			this->lbl_cant->Size = System::Drawing::Size(62, 17);
			this->lbl_cant->TabIndex = 14;
			this->lbl_cant->Text = L"Cantidad";
			// 
			// tb_discount
			// 
			this->tb_discount->Location = System::Drawing::Point(347, 220);
			this->tb_discount->Name = L"tb_discount";
			this->tb_discount->Size = System::Drawing::Size(79, 20);
			this->tb_discount->TabIndex = 11;
			// 
			// lbl_discount
			// 
			this->lbl_discount->AutoSize = true;
			this->lbl_discount->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_discount->Location = System::Drawing::Point(344, 200);
			this->lbl_discount->Name = L"lbl_discount";
			this->lbl_discount->Size = System::Drawing::Size(95, 17);
			this->lbl_discount->TabIndex = 10;
			this->lbl_discount->Text = L"Descuento (%)";
			// 
			// lbl_busqueda
			// 
			this->lbl_busqueda->AutoSize = true;
			this->lbl_busqueda->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_busqueda->Location = System::Drawing::Point(14, 200);
			this->lbl_busqueda->Name = L"lbl_busqueda";
			this->lbl_busqueda->Size = System::Drawing::Size(186, 17);
			this->lbl_busqueda->TabIndex = 8;
			this->lbl_busqueda->Text = L"Buscar producto (por código)";
			// 
			// lbl_vendedor
			// 
			this->lbl_vendedor->AutoSize = true;
			this->lbl_vendedor->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_vendedor->Location = System::Drawing::Point(544, 123);
			this->lbl_vendedor->Name = L"lbl_vendedor";
			this->lbl_vendedor->Size = System::Drawing::Size(73, 17);
			this->lbl_vendedor->TabIndex = 6;
			this->lbl_vendedor->Text = L"Vendedor: ";
			// 
			// cb_formapago
			// 
			this->cb_formapago->FormattingEnabled = true;
			this->cb_formapago->Location = System::Drawing::Point(711, 80);
			this->cb_formapago->Name = L"cb_formapago";
			this->cb_formapago->Size = System::Drawing::Size(141, 21);
			this->cb_formapago->TabIndex = 5;
			// 
			// lbl_payment
			// 
			this->lbl_payment->AutoSize = true;
			this->lbl_payment->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_payment->Location = System::Drawing::Point(708, 59);
			this->lbl_payment->Name = L"lbl_payment";
			this->lbl_payment->Size = System::Drawing::Size(100, 17);
			this->lbl_payment->TabIndex = 4;
			this->lbl_payment->Text = L"Forma de pago";
			// 
			// cb_client
			// 
			this->cb_client->FormattingEnabled = true;
			this->cb_client->Location = System::Drawing::Point(547, 80);
			this->cb_client->Name = L"cb_client";
			this->cb_client->Size = System::Drawing::Size(141, 21);
			this->cb_client->TabIndex = 3;
			// 
			// lbl_client
			// 
			this->lbl_client->AutoSize = true;
			this->lbl_client->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_client->Location = System::Drawing::Point(544, 59);
			this->lbl_client->Name = L"lbl_client";
			this->lbl_client->Size = System::Drawing::Size(49, 17);
			this->lbl_client->TabIndex = 2;
			this->lbl_client->Text = L"Cliente";
			// 
			// panel_pago
			// 
			this->panel_pago->BackColor = System::Drawing::Color::White;
			this->panel_pago->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_pago->Controls->Add(this->tb_masIVA);
			this->panel_pago->Controls->Add(this->lbl_masIVA);
			this->panel_pago->Controls->Add(this->tb_totaldevuelto);
			this->panel_pago->Controls->Add(this->lbl_totaldevuelto);
			this->panel_pago->Controls->Add(this->tb_totalpagado);
			this->panel_pago->Controls->Add(this->lbl_totalpagado);
			this->panel_pago->Controls->Add(this->tb_subtotal);
			this->panel_pago->Controls->Add(this->tb_totalpagar);
			this->panel_pago->Controls->Add(this->lbl_subtotal);
			this->panel_pago->Controls->Add(this->lbl_total_pagar);
			this->panel_pago->Location = System::Drawing::Point(34, 569);
			this->panel_pago->Name = L"panel_pago";
			this->panel_pago->Size = System::Drawing::Size(794, 71);
			this->panel_pago->TabIndex = 33;
			// 
			// tb_masIVA
			// 
			this->tb_masIVA->Location = System::Drawing::Point(119, 31);
			this->tb_masIVA->Name = L"tb_masIVA";
			this->tb_masIVA->ReadOnly = true;
			this->tb_masIVA->Size = System::Drawing::Size(89, 20);
			this->tb_masIVA->TabIndex = 40;
			// 
			// lbl_masIVA
			// 
			this->lbl_masIVA->AutoSize = true;
			this->lbl_masIVA->BackColor = System::Drawing::SystemColors::MenuBar;
			this->lbl_masIVA->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_masIVA->Location = System::Drawing::Point(116, 12);
			this->lbl_masIVA->Name = L"lbl_masIVA";
			this->lbl_masIVA->Size = System::Drawing::Size(64, 17);
			this->lbl_masIVA->TabIndex = 39;
			this->lbl_masIVA->Text = L"+15% IVA";
			// 
			// tb_totaldevuelto
			// 
			this->tb_totaldevuelto->Location = System::Drawing::Point(666, 32);
			this->tb_totaldevuelto->Name = L"tb_totaldevuelto";
			this->tb_totaldevuelto->ReadOnly = true;
			this->tb_totaldevuelto->Size = System::Drawing::Size(89, 20);
			this->tb_totaldevuelto->TabIndex = 38;
			// 
			// lbl_totaldevuelto
			// 
			this->lbl_totaldevuelto->AutoSize = true;
			this->lbl_totaldevuelto->BackColor = System::Drawing::SystemColors::MenuBar;
			this->lbl_totaldevuelto->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_totaldevuelto->Location = System::Drawing::Point(663, 12);
			this->lbl_totaldevuelto->Name = L"lbl_totaldevuelto";
			this->lbl_totaldevuelto->Size = System::Drawing::Size(121, 17);
			this->lbl_totaldevuelto->TabIndex = 37;
			this->lbl_totaldevuelto->Text = L"Total devuelto (C$)";
			// 
			// tb_totalpagado
			// 
			this->tb_totalpagado->Location = System::Drawing::Point(543, 31);
			this->tb_totalpagado->Name = L"tb_totalpagado";
			this->tb_totalpagado->Size = System::Drawing::Size(89, 20);
			this->tb_totalpagado->TabIndex = 36;
			this->tb_totalpagado->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Generar_factura::tb_totalpagado_KeyDown);
			// 
			// lbl_totalpagado
			// 
			this->lbl_totalpagado->AutoSize = true;
			this->lbl_totalpagado->BackColor = System::Drawing::SystemColors::MenuBar;
			this->lbl_totalpagado->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_totalpagado->Location = System::Drawing::Point(540, 12);
			this->lbl_totalpagado->Name = L"lbl_totalpagado";
			this->lbl_totalpagado->Size = System::Drawing::Size(114, 17);
			this->lbl_totalpagado->TabIndex = 35;
			this->lbl_totalpagado->Text = L"Total pagado (C$)";
			// 
			// tb_subtotal
			// 
			this->tb_subtotal->Location = System::Drawing::Point(16, 31);
			this->tb_subtotal->Name = L"tb_subtotal";
			this->tb_subtotal->ReadOnly = true;
			this->tb_subtotal->Size = System::Drawing::Size(89, 20);
			this->tb_subtotal->TabIndex = 32;
			// 
			// tb_totalpagar
			// 
			this->tb_totalpagar->Location = System::Drawing::Point(221, 31);
			this->tb_totalpagar->Name = L"tb_totalpagar";
			this->tb_totalpagar->ReadOnly = true;
			this->tb_totalpagar->Size = System::Drawing::Size(89, 20);
			this->tb_totalpagar->TabIndex = 34;
			// 
			// lbl_subtotal
			// 
			this->lbl_subtotal->AutoSize = true;
			this->lbl_subtotal->BackColor = System::Drawing::SystemColors::MenuBar;
			this->lbl_subtotal->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_subtotal->Location = System::Drawing::Point(13, 12);
			this->lbl_subtotal->Name = L"lbl_subtotal";
			this->lbl_subtotal->Size = System::Drawing::Size(86, 17);
			this->lbl_subtotal->TabIndex = 31;
			this->lbl_subtotal->Text = L"Subtotal (C$)";
			// 
			// lbl_total_pagar
			// 
			this->lbl_total_pagar->AutoSize = true;
			this->lbl_total_pagar->BackColor = System::Drawing::SystemColors::MenuBar;
			this->lbl_total_pagar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_total_pagar->Location = System::Drawing::Point(218, 12);
			this->lbl_total_pagar->Name = L"lbl_total_pagar";
			this->lbl_total_pagar->Size = System::Drawing::Size(145, 17);
			this->lbl_total_pagar->TabIndex = 33;
			this->lbl_total_pagar->Text = L"Total a pagar (con IVA)";
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Generar_factura
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(879, 708);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel_fondo);
			this->MaximizeBox = false;
			this->Name = L"Generar_factura";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Generar factura";
			this->Load += gcnew System::EventHandler(this, &Generar_factura::Generar_factura_Load);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel_fondo->ResumeLayout(false);
			this->panel_fondo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_prods))->EndInit();
			this->panel_pago->ResumeLayout(false);
			this->panel_pago->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Generar_factura_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se carga una imagen que simula una lupa en el buscador
		this->pictureBox_buscar->Image = Image::FromFile("imagenbuscar.png");

		// Mostramos el vendedor (es decir la persona que accedió al sistema) de la factura
		cb_vendedor->Text = username;

		// Se llenan algunos comboBoxes para la selección de clientes, formas de pago y vendedores
		archivoCliente::obtenerClientes(cb_client);
		archivoFactura::obtenerMetodoPago(cb_formapago);
		
		// Mostramos el código generado automáticamente de la factura en vista previa
		string codigofactura = codigofac::generarCodigo_fac();

		// Mostramos la fecha y hora en la que empezó el movimiento
		string fechaEmision = archivoFactura::obtenerFecha();
		string horaEmision = archivoFactura::obtenerHora();

		// Pasamos de std::string a System::String para una muestra correcta del código, fecha y hora de la factura
		lbl_numfactura->Text = gcnew String(codigofactura.c_str());
		lbl_fecha->Text = gcnew String(fechaEmision.c_str());
		lbl_hora->Text = gcnew String(horaEmision.c_str());

		// Mostramos los datos guardados sobre el encabezado de la factura
		archivoConfiguracion::verDatos(nEmp, dEmp, tEmp, eEmp);

		/* Si hay registros en la configuración se mostrarán en la vista previa de la factura,...
		...de otro modo se mostrará el texto por defecto del label*/
		if (nEmp->Trim() != "") {
			lbl_nomempresa->Text = nEmp;
		}
		if (dEmp->Trim() != "") {
			lbl_dirempresa->Text = dEmp;
		}
		if (tEmp->Trim() != "") {
			lbl_telempresa->Text = tEmp;
		}
		if (eEmp->Trim() != "") {
			lbl_correoempresa->Text = eEmp;
		}
	}
	// Este control identifica cuando el usuario haya dado "Enter" a un TextBox
	private: System::Void tb_totalpagado_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			// En caso que el usuario haya dado Enter, calculamos la diferencia del total a pagar y el total pagado
			// Esta operación será efectuada siempre que la forma de pago del usuario haya sido en efectivo
			if (cb_formapago->Text == "Efectivo") {
				// Verificamos que el total pagado sea mayor o igual que el total a pagar
				int error = 0;
				String^ totalPayment_isgreaterThan_totalPaid = "El pago debe de quedar saldado.";
				validate::isTxtBox2_greaterThan(tb_totalpagar, tb_totalpagado, errorProvider, totalPayment_isgreaterThan_totalPaid, error);
				// Comprobamos de nuevo si hubo un error en el proceso e interrumpimos el proceso de factura en caso de haber ocurrido
				if (error > 0) {
					return;
				}
				else {
					/* Si no hubo errores, convertimos los valores especificados en flotantes y luego a cadena,...
					...en el TextBox*/
					this->tb_totaldevuelto->Text = (Convert::ToSingle(tb_totalpagado->Text) - Convert::ToSingle(tb_totalpagar->Text)).ToString("N2");
				}
			}
		}
	}
	private: System::Void pictureBox_buscar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se convierte el texto contenido en el textbox a uno manejable para C++ estándar
		string busqueda = conversion::to_stdstring(this->tb_busqueda->Text);
		
		// Declaramos algunas variables a fin de tener una vista previa de los datos originales
		string desc = "";
		string uMeasure = "";
		string exist = "";
		string pUnit = "";

		archivoProducto::buscarProductos_porCodigo(busqueda, desc, uMeasure, exist, pUnit);

		// Se asignan los valores obtenidos a los labels de información del producto cambiando de std::string a System::String
		lbl_descripcionprod->Text = gcnew String(desc.c_str());
		lbl_uMeasure->Text = gcnew String(uMeasure.c_str());
		tb_existCan->Text = gcnew String(exist.c_str());
		lbl_pUnit->Text = gcnew String(pUnit.c_str());
		this->Refresh(); // Se actualizan los componentes del formulario para mostrar la información del producto correctamente
	}
	private: System::Void btn_adicionar_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		String^ client_notSelected = "Debe seleccionar un cliente.";
		String^ paymentf_notSpecified = "Especifíque una forma de pago.";
		String^ admin_notSelected = "Debe seleccionar un vendedor.";
		String^ empty_txtBox = "Este campo es obligatorio.";
		String^ product_notSearched = "Debe buscar un producto el cual vender.";
		String^ unit_isPosInt = "La unidad de medida del producto es por unidades. Debe ingresar valores enteros positivos.";
		String^ unit_isPosFloat = "Debe de ingresar valores numéricos positivos.";
		String^ moreQuantity_thanExisting = "La cantidad demandada sobrepasa a la cantidad existente en nuestro inventario.";

		// Primeramente, validamos las entradas para la correcta adición de la compra del producto en cuestión
		
		// 1. Verificamos si se ha seleccionado un elemento de los comboBoxes y si se ha ingresado una cantidad
		validate::isComboBox_notEmpty(cb_client, errorProvider, client_notSelected, error);
		validate::isComboBox_notEmpty(cb_formapago, errorProvider, paymentf_notSpecified, error);
		//validate::isComboBox_notEmpty(cb_vendedor, errorProvider, admin_notSelected, error);
		validate::isTxtBox_notEmpty(tb_cant, errorProvider, empty_txtBox, error);

		// 2. Verificamos si ya se buscó el código de un producto
		validate::isTxtBox_notEmpty(tb_busqueda, errorProvider, product_notSearched, error);
		// 3. Verificamos si la entrada de descuento es correcta
		if (tb_discount->Text != "0") {
			validate::isTxtBox_posFloat(tb_discount, errorProvider, empty_txtBox, error);
		}

		// Si aún no han habido errores (es decir, se buscó un producto existente) verificamos los...
		// ...valores de cantidad y descuento (en caso de aplicarse uno)
		if (error == 0) {
			// En caso de que la unidad de medida del producto es por unidad verificamos que...
			if (lbl_uMeasure->Text == "u") {
				// ¿Es un valor entero positivo?
				validate::isTxtBox_posInt(tb_cant, errorProvider, unit_isPosInt, error);
			}
			else { // De otro modo, permitivos el uso de valores decimales positivos para la cantidad
				validate::isTxtBox_posFloat(tb_cant, errorProvider, unit_isPosFloat, error);
			}
		}

		// 4. Verificamos si la cantidad a pedir es mayor que la existente en inventario
		validate::isTxtBox_greaterThan(tb_existCan, tb_cant, errorProvider, moreQuantity_thanExisting, error);

		// En caso de encontrarse errores de entrada, interrumpimos el proceso de facturación para ese producto
		if (error > 0) {
			return;
		}

		// Convertimos los valores de los textBoxes a unos manejables para las operaciones
		string cant = conversion::to_stdstring(tb_cant->Text);
		float valCant = stof(cant);

		string pUnit = conversion::to_stdstring(lbl_pUnit->Text);
		float valpUnit = stof(pUnit);

		string discount = conversion::to_stdstring(tb_discount->Text);
		float valDiscount = stof(discount);

		// Adicionamos el producto en el datagridview
		archivoFactura::agregarProducto_en_dgv(dgv_prods, lbl_descripcionprod->Text, valCant, valpUnit, valDiscount);
		archivoFactura::calcularTotal(dgv_prods, tb_subtotal, tb_masIVA, tb_totalpagar);

		// Limpiamos los textBoxes una vez adicionado el producto
		this->tb_busqueda->Text = "";
		this->tb_cant->Text = "";
		this->tb_discount->Text = "";
		this->lbl_descripcionprod->Text = "";
		this->lbl_pUnit->Text = "";
		this->lbl_uMeasure->Text = "";

		// Si el cliente paga en tarjeta, saldaremos todo el pago automáticamente
		if (cb_formapago->Text == "Tarjeta") {
			this->tb_totalpagado->Text = tb_totalpagar->Text;
			this->tb_totaldevuelto->Text = "0.00";
		}

		this->Refresh(); // Refrescamos el formulario para mostrar correctamente los cambios
	}
	private: System::Void btn_generarfactura_Click(System::Object^ sender, System::EventArgs^ e) {
		/*Antes de llamar a la función que permitirá registrar los productos adicionados del datagridview...
		..., se convierten los valores a sus derivados por C++ estándar*/
		string numFact = conversion::to_stdstring(lbl_numfactura->Text);
		string fEmision = conversion::to_stdstring(lbl_fecha->Text);
		string hEmision = conversion::to_stdstring(lbl_hora->Text);
		string client = conversion::to_stdstring(cb_client->Text);
		string payMethod = conversion::to_stdstring(cb_formapago->Text);
		string cashier = conversion::to_stdstring(cb_vendedor->Text);
		string subTotal = conversion::to_stdstring(tb_subtotal->Text);
		string totalPayment = conversion::to_stdstring(tb_totalpagar->Text);
		string totalPaid = conversion::to_stdstring(tb_totalpagado->Text);
		string change = conversion::to_stdstring(tb_totaldevuelto->Text);
		double mIVA = stof(conversion::to_stdstring(tb_masIVA->Text));

		/* Haremos una última validación para verificar el total pagado,...
		...interrumpiendo el proceso si es negativo*/
		int error = 0;
		String^ totalPayment_isgreaterThan_totalPaid = "El pago debe de quedar saldado.";
		validate::isTxtBox2_greaterThan(tb_totalpagar, tb_totalpagado, errorProvider, totalPayment_isgreaterThan_totalPaid, error);

		if (error > 0) {
			return;
		}
		
		// Registramos los productos del dgv
		archivoFactura::registrar_datosFactura_delDGV(dgv_prods, numFact, fEmision, hEmision, 
								client, cashier, subTotal, payMethod, totalPayment, totalPaid, change);
		
		// Convertimos también la información acerca de la empresa de System::String a std::string
		string nomEmpresa = conversion::to_stdstring(lbl_nomempresa->Text);
		string dirEmpresa = conversion::to_stdstring(lbl_dirempresa->Text);
		string emailEmpresa = conversion::to_stdstring(lbl_correoempresa->Text);
		string telEmpresa = conversion::to_stdstring(lbl_telempresa->Text);

		// Luego realizamos un comprobante de factura
		archivoFactura::diseñarFactura(numFact, client, fEmision, hEmision, cashier, nomEmpresa, dirEmpresa,
										telEmpresa, emailEmpresa, mIVA);

		/* Ya terminado todo el proceso de factura, es necesario reflejar los movimientos de productos en el inventario...
		...por lo que restamos las cantidades sacadas de este.*/
		archivoFactura::actualizarInventario(numFact, false);
	}
	};
}