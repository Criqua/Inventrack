#pragma once
#include "SystemString_toStdString.h"
#include "productos/auto_code.h"
#include "Agregar_grupo.h"
#include "unidad de medida/uMedidas_archivadas.h"
#include "Modificar_producto.h"
#include "Compras.h"
#include "Historial_compras.h"
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
	/// Resumen de Productos
	/// </summary>
	public ref class Productos : public System::Windows::Forms::Form
	{
	public:
		Productos(void)
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
		~Productos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pB_eliminar;
	private: System::Windows::Forms::PictureBox^ pB_modificar;
	private: System::Windows::Forms::PictureBox^ pictureBox_buscar;
	private: System::Windows::Forms::TextBox^ tb_busqueda;
	private: System::Windows::Forms::DataGridView^ dgv_prod;
	private: System::Windows::Forms::Panel^ panel_headinfo2;
	private: System::Windows::Forms::Label^ lbl_verprod;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::ComboBox^ cb_umedida_despleg;
	private: System::Windows::Forms::PictureBox^ pb_agregarGrupo;
	private: System::Windows::Forms::ComboBox^ cb_grupo_despleg;
	private: System::Windows::Forms::TextBox^ tb_pUnit;
	private: System::Windows::Forms::Label^ lbl_pUnit;
	private: System::Windows::Forms::TextBox^ tb_exist;
	private: System::Windows::Forms::Label^ lbl_exist;
	private: System::Windows::Forms::Label^ lbl_group;
	private: System::Windows::Forms::Button^ btn_guardar;
	private: System::Windows::Forms::Label^ lbl_surnames;
	private: System::Windows::Forms::TextBox^ tb_descripcion;
	private: System::Windows::Forms::Label^ lbl_desc;
	private: System::Windows::Forms::Panel^ panel_headinfo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_registerprod;
	private: System::Windows::Forms::Label^ lbl_ubic;
	private: System::Windows::Forms::TextBox^ tb_emin;
	private: System::Windows::Forms::Label^ lbl_emin;
	private: System::Windows::Forms::TextBox^ tb_fexp;
	private: System::Windows::Forms::Label^ lbl_fexp;
	private: System::Windows::Forms::TextBox^ tb_ubic;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ btn_compras;

	private: System::Windows::Forms::PictureBox^ pb_flecha;
	// Declaramos variables que necesitan ser usadas en el formulario de "Modificar_proveedores", a fin de tener una vista previa de los datos originales
	public: String^ codeProduct = "";
	public: String^ groupProduct = "";
	public: String^ descProduct = "";
	public: String^ uMeasureProduct = "";
	public: String^ existProduct = "";
	public: String^ existminProduct = "";
	public: String^ ubicProduct = "";
	public: String^ pUnitProduct = "";
	public: String^ fExpProduct = "";
	// Se declara una variable booleana que indicará si fue encontrado o no el proveedor buscado
	public: bool found;
	private: System::Windows::Forms::PictureBox^ pB_flecha2;
	public:
	private: System::Windows::Forms::Button^ btn_historialComp;
		   // Declaramos variables que obtendrán la información del usuario que inició sesión
	public: String^ username;
	public: String^ role;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pB_eliminar = (gcnew System::Windows::Forms::PictureBox());
			this->pB_modificar = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_buscar = (gcnew System::Windows::Forms::PictureBox());
			this->tb_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->dgv_prod = (gcnew System::Windows::Forms::DataGridView());
			this->panel_headinfo2 = (gcnew System::Windows::Forms::Panel());
			this->lbl_verprod = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->tb_fexp = (gcnew System::Windows::Forms::TextBox());
			this->lbl_fexp = (gcnew System::Windows::Forms::Label());
			this->tb_ubic = (gcnew System::Windows::Forms::TextBox());
			this->lbl_ubic = (gcnew System::Windows::Forms::Label());
			this->tb_emin = (gcnew System::Windows::Forms::TextBox());
			this->lbl_emin = (gcnew System::Windows::Forms::Label());
			this->cb_umedida_despleg = (gcnew System::Windows::Forms::ComboBox());
			this->pb_agregarGrupo = (gcnew System::Windows::Forms::PictureBox());
			this->cb_grupo_despleg = (gcnew System::Windows::Forms::ComboBox());
			this->tb_pUnit = (gcnew System::Windows::Forms::TextBox());
			this->lbl_pUnit = (gcnew System::Windows::Forms::Label());
			this->tb_exist = (gcnew System::Windows::Forms::TextBox());
			this->lbl_exist = (gcnew System::Windows::Forms::Label());
			this->lbl_group = (gcnew System::Windows::Forms::Label());
			this->btn_guardar = (gcnew System::Windows::Forms::Button());
			this->lbl_surnames = (gcnew System::Windows::Forms::Label());
			this->tb_descripcion = (gcnew System::Windows::Forms::TextBox());
			this->lbl_desc = (gcnew System::Windows::Forms::Label());
			this->panel_headinfo = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_registerprod = (gcnew System::Windows::Forms::Label());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->btn_compras = (gcnew System::Windows::Forms::Button());
			this->pb_flecha = (gcnew System::Windows::Forms::PictureBox());
			this->pB_flecha2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_historialComp = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_eliminar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_modificar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_prod))->BeginInit();
			this->panel_headinfo2->SuspendLayout();
			this->panel_shadowing->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_agregarGrupo))->BeginInit();
			this->panel_headinfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_flecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_flecha2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightGray;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->pictureBox_buscar);
			this->panel1->Controls->Add(this->tb_busqueda);
			this->panel1->Controls->Add(this->dgv_prod);
			this->panel1->Controls->Add(this->panel_headinfo2);
			this->panel1->Location = System::Drawing::Point(6, 449);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(673, 426);
			this->panel1->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->pB_eliminar);
			this->panel2->Controls->Add(this->pB_modificar);
			this->panel2->Location = System::Drawing::Point(441, 51);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(50, 22);
			this->panel2->TabIndex = 13;
			// 
			// pB_eliminar
			// 
			this->pB_eliminar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pB_eliminar->Location = System::Drawing::Point(27, 2);
			this->pB_eliminar->Name = L"pB_eliminar";
			this->pB_eliminar->Size = System::Drawing::Size(15, 15);
			this->pB_eliminar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_eliminar->TabIndex = 13;
			this->pB_eliminar->TabStop = false;
			this->pB_eliminar->Click += gcnew System::EventHandler(this, &Productos::pB_eliminar_Click);
			// 
			// pB_modificar
			// 
			this->pB_modificar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pB_modificar->Location = System::Drawing::Point(6, 2);
			this->pB_modificar->Name = L"pB_modificar";
			this->pB_modificar->Size = System::Drawing::Size(17, 17);
			this->pB_modificar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_modificar->TabIndex = 13;
			this->pB_modificar->TabStop = false;
			this->pB_modificar->Click += gcnew System::EventHandler(this, &Productos::pB_modificar_Click);
			// 
			// pictureBox_buscar
			// 
			this->pictureBox_buscar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox_buscar->Location = System::Drawing::Point(416, 53);
			this->pictureBox_buscar->Name = L"pictureBox_buscar";
			this->pictureBox_buscar->Size = System::Drawing::Size(17, 17);
			this->pictureBox_buscar->TabIndex = 0;
			this->pictureBox_buscar->TabStop = false;
			this->pictureBox_buscar->Click += gcnew System::EventHandler(this, &Productos::pictureBox_buscar_Click);
			// 
			// tb_busqueda
			// 
			this->tb_busqueda->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_busqueda->Location = System::Drawing::Point(22, 51);
			this->tb_busqueda->Name = L"tb_busqueda";
			this->tb_busqueda->Size = System::Drawing::Size(413, 22);
			this->tb_busqueda->TabIndex = 8;
			this->tb_busqueda->Enter += gcnew System::EventHandler(this, &Productos::tb_busqueda_Enter);
			this->tb_busqueda->Leave += gcnew System::EventHandler(this, &Productos::tb_busqueda_Leave);
			// 
			// dgv_prod
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_prod->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgv_prod->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_prod->Location = System::Drawing::Point(15, 84);
			this->dgv_prod->Name = L"dgv_prod";
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_prod->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dgv_prod->Size = System::Drawing::Size(641, 340);
			this->dgv_prod->TabIndex = 7;
			// 
			// panel_headinfo2
			// 
			this->panel_headinfo2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_headinfo2->Controls->Add(this->lbl_verprod);
			this->panel_headinfo2->Location = System::Drawing::Point(3, 5);
			this->panel_headinfo2->Name = L"panel_headinfo2";
			this->panel_headinfo2->Size = System::Drawing::Size(667, 33);
			this->panel_headinfo2->TabIndex = 6;
			// 
			// lbl_verprod
			// 
			this->lbl_verprod->AutoSize = true;
			this->lbl_verprod->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_verprod->Location = System::Drawing::Point(14, 7);
			this->lbl_verprod->Name = L"lbl_verprod";
			this->lbl_verprod->Size = System::Drawing::Size(171, 19);
			this->lbl_verprod->TabIndex = 0;
			this->lbl_verprod->Text = L"Ver y modificar productos";
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->tb_fexp);
			this->panel_shadowing->Controls->Add(this->lbl_fexp);
			this->panel_shadowing->Controls->Add(this->tb_ubic);
			this->panel_shadowing->Controls->Add(this->lbl_ubic);
			this->panel_shadowing->Controls->Add(this->tb_emin);
			this->panel_shadowing->Controls->Add(this->lbl_emin);
			this->panel_shadowing->Controls->Add(this->cb_umedida_despleg);
			this->panel_shadowing->Controls->Add(this->pb_agregarGrupo);
			this->panel_shadowing->Controls->Add(this->cb_grupo_despleg);
			this->panel_shadowing->Controls->Add(this->tb_pUnit);
			this->panel_shadowing->Controls->Add(this->lbl_pUnit);
			this->panel_shadowing->Controls->Add(this->tb_exist);
			this->panel_shadowing->Controls->Add(this->lbl_exist);
			this->panel_shadowing->Controls->Add(this->lbl_group);
			this->panel_shadowing->Controls->Add(this->btn_guardar);
			this->panel_shadowing->Controls->Add(this->lbl_surnames);
			this->panel_shadowing->Controls->Add(this->tb_descripcion);
			this->panel_shadowing->Controls->Add(this->lbl_desc);
			this->panel_shadowing->Controls->Add(this->panel_headinfo);
			this->panel_shadowing->Location = System::Drawing::Point(6, 5);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(673, 314);
			this->panel_shadowing->TabIndex = 10;
			// 
			// tb_fexp
			// 
			this->tb_fexp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_fexp->Location = System::Drawing::Point(142, 206);
			this->tb_fexp->Name = L"tb_fexp";
			this->tb_fexp->Size = System::Drawing::Size(106, 22);
			this->tb_fexp->TabIndex = 36;
			this->tb_fexp->Enter += gcnew System::EventHandler(this, &Productos::tb_fexp_Enter);
			this->tb_fexp->Leave += gcnew System::EventHandler(this, &Productos::tb_fexp_Leave);
			// 
			// lbl_fexp
			// 
			this->lbl_fexp->AutoSize = true;
			this->lbl_fexp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_fexp->Location = System::Drawing::Point(23, 208);
			this->lbl_fexp->Name = L"lbl_fexp";
			this->lbl_fexp->Size = System::Drawing::Size(112, 15);
			this->lbl_fexp->TabIndex = 35;
			this->lbl_fexp->Text = L"Fecha de expiración";
			// 
			// tb_ubic
			// 
			this->tb_ubic->Location = System::Drawing::Point(142, 168);
			this->tb_ubic->Name = L"tb_ubic";
			this->tb_ubic->Size = System::Drawing::Size(106, 20);
			this->tb_ubic->TabIndex = 34;
			// 
			// lbl_ubic
			// 
			this->lbl_ubic->AutoSize = true;
			this->lbl_ubic->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_ubic->Location = System::Drawing::Point(75, 170);
			this->lbl_ubic->Name = L"lbl_ubic";
			this->lbl_ubic->Size = System::Drawing::Size(60, 15);
			this->lbl_ubic->TabIndex = 33;
			this->lbl_ubic->Text = L"Ubicación";
			// 
			// tb_emin
			// 
			this->tb_emin->Location = System::Drawing::Point(355, 128);
			this->tb_emin->Name = L"tb_emin";
			this->tb_emin->Size = System::Drawing::Size(59, 20);
			this->tb_emin->TabIndex = 32;
			// 
			// lbl_emin
			// 
			this->lbl_emin->AutoSize = true;
			this->lbl_emin->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_emin->Location = System::Drawing::Point(233, 130);
			this->lbl_emin->Name = L"lbl_emin";
			this->lbl_emin->Size = System::Drawing::Size(116, 15);
			this->lbl_emin->TabIndex = 31;
			this->lbl_emin->Text = L"Exist. / Cant. mínima";
			// 
			// cb_umedida_despleg
			// 
			this->cb_umedida_despleg->FormattingEnabled = true;
			this->cb_umedida_despleg->Location = System::Drawing::Point(543, 92);
			this->cb_umedida_despleg->Name = L"cb_umedida_despleg";
			this->cb_umedida_despleg->Size = System::Drawing::Size(104, 21);
			this->cb_umedida_despleg->TabIndex = 30;
			// 
			// pb_agregarGrupo
			// 
			this->pb_agregarGrupo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pb_agregarGrupo->Location = System::Drawing::Point(287, 54);
			this->pb_agregarGrupo->Name = L"pb_agregarGrupo";
			this->pb_agregarGrupo->Size = System::Drawing::Size(18, 17);
			this->pb_agregarGrupo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pb_agregarGrupo->TabIndex = 29;
			this->pb_agregarGrupo->TabStop = false;
			this->pb_agregarGrupo->Click += gcnew System::EventHandler(this, &Productos::pb_agregarGrupo_Click);
			// 
			// cb_grupo_despleg
			// 
			this->cb_grupo_despleg->FormattingEnabled = true;
			this->cb_grupo_despleg->Location = System::Drawing::Point(142, 52);
			this->cb_grupo_despleg->Name = L"cb_grupo_despleg";
			this->cb_grupo_despleg->Size = System::Drawing::Size(121, 21);
			this->cb_grupo_despleg->TabIndex = 28;
			// 
			// tb_pUnit
			// 
			this->tb_pUnit->Location = System::Drawing::Point(543, 128);
			this->tb_pUnit->Name = L"tb_pUnit";
			this->tb_pUnit->Size = System::Drawing::Size(66, 20);
			this->tb_pUnit->TabIndex = 27;
			// 
			// lbl_pUnit
			// 
			this->lbl_pUnit->AutoSize = true;
			this->lbl_pUnit->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_pUnit->Location = System::Drawing::Point(440, 130);
			this->lbl_pUnit->Name = L"lbl_pUnit";
			this->lbl_pUnit->Size = System::Drawing::Size(92, 15);
			this->lbl_pUnit->TabIndex = 26;
			this->lbl_pUnit->Text = L"Precio unit. (C$)";
			// 
			// tb_exist
			// 
			this->tb_exist->Location = System::Drawing::Point(142, 128);
			this->tb_exist->Name = L"tb_exist";
			this->tb_exist->Size = System::Drawing::Size(59, 20);
			this->tb_exist->TabIndex = 25;
			// 
			// lbl_exist
			// 
			this->lbl_exist->AutoSize = true;
			this->lbl_exist->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_exist->Location = System::Drawing::Point(13, 130);
			this->lbl_exist->Name = L"lbl_exist";
			this->lbl_exist->Size = System::Drawing::Size(122, 15);
			this->lbl_exist->TabIndex = 24;
			this->lbl_exist->Text = L"Existencias / Cantidad";
			// 
			// lbl_group
			// 
			this->lbl_group->AutoSize = true;
			this->lbl_group->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_group->Location = System::Drawing::Point(95, 52);
			this->lbl_group->Name = L"lbl_group";
			this->lbl_group->Size = System::Drawing::Size(40, 15);
			this->lbl_group->TabIndex = 20;
			this->lbl_group->Text = L"Grupo";
			// 
			// btn_guardar
			// 
			this->btn_guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_guardar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_guardar->ForeColor = System::Drawing::Color::White;
			this->btn_guardar->Location = System::Drawing::Point(303, 257);
			this->btn_guardar->Name = L"btn_guardar";
			this->btn_guardar->Size = System::Drawing::Size(82, 33);
			this->btn_guardar->TabIndex = 18;
			this->btn_guardar->Text = L"Guardar";
			this->btn_guardar->UseVisualStyleBackColor = false;
			this->btn_guardar->Click += gcnew System::EventHandler(this, &Productos::btn_guardar_Click);
			// 
			// lbl_surnames
			// 
			this->lbl_surnames->AutoSize = true;
			this->lbl_surnames->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_surnames->Location = System::Drawing::Point(433, 95);
			this->lbl_surnames->Name = L"lbl_surnames";
			this->lbl_surnames->Size = System::Drawing::Size(104, 15);
			this->lbl_surnames->TabIndex = 8;
			this->lbl_surnames->Text = L"Unidad de medida";
			// 
			// tb_descripcion
			// 
			this->tb_descripcion->Location = System::Drawing::Point(142, 92);
			this->tb_descripcion->Name = L"tb_descripcion";
			this->tb_descripcion->Size = System::Drawing::Size(272, 20);
			this->tb_descripcion->TabIndex = 5;
			// 
			// lbl_desc
			// 
			this->lbl_desc->AutoSize = true;
			this->lbl_desc->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_desc->Location = System::Drawing::Point(65, 94);
			this->lbl_desc->Name = L"lbl_desc";
			this->lbl_desc->Size = System::Drawing::Size(70, 15);
			this->lbl_desc->TabIndex = 4;
			this->lbl_desc->Text = L"Descripción";
			// 
			// panel_headinfo
			// 
			this->panel_headinfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_headinfo->Controls->Add(this->label1);
			this->panel_headinfo->Controls->Add(this->label_registerprod);
			this->panel_headinfo->Location = System::Drawing::Point(3, 4);
			this->panel_headinfo->Name = L"panel_headinfo";
			this->panel_headinfo->Size = System::Drawing::Size(667, 33);
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
			// label_registerprod
			// 
			this->label_registerprod->AutoSize = true;
			this->label_registerprod->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label_registerprod->Location = System::Drawing::Point(10, 6);
			this->label_registerprod->Name = L"label_registerprod";
			this->label_registerprod->Size = System::Drawing::Size(132, 19);
			this->label_registerprod->TabIndex = 0;
			this->label_registerprod->Text = L"Registrar productos";
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// btn_compras
			// 
			this->btn_compras->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_compras->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_compras->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_compras->Location = System::Drawing::Point(6, 334);
			this->btn_compras->Name = L"btn_compras";
			this->btn_compras->Size = System::Drawing::Size(673, 49);
			this->btn_compras->TabIndex = 12;
			this->btn_compras->Text = L"   Realizar compras";
			this->btn_compras->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_compras->UseVisualStyleBackColor = false;
			this->btn_compras->Click += gcnew System::EventHandler(this, &Productos::btn_compras_Click);
			// 
			// pb_flecha
			// 
			this->pb_flecha->Location = System::Drawing::Point(144, 343);
			this->pb_flecha->Name = L"pb_flecha";
			this->pb_flecha->Size = System::Drawing::Size(28, 33);
			this->pb_flecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pb_flecha->TabIndex = 13;
			this->pb_flecha->TabStop = false;
			// 
			// pB_flecha2
			// 
			this->pB_flecha2->Location = System::Drawing::Point(191, 398);
			this->pB_flecha2->Name = L"pB_flecha2";
			this->pB_flecha2->Size = System::Drawing::Size(28, 33);
			this->pB_flecha2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_flecha2->TabIndex = 15;
			this->pB_flecha2->TabStop = false;
			// 
			// btn_historialComp
			// 
			this->btn_historialComp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_historialComp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_historialComp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_historialComp->Location = System::Drawing::Point(6, 389);
			this->btn_historialComp->Name = L"btn_historialComp";
			this->btn_historialComp->Size = System::Drawing::Size(673, 49);
			this->btn_historialComp->TabIndex = 14;
			this->btn_historialComp->Text = L"   Ver historial de compras";
			this->btn_historialComp->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_historialComp->UseVisualStyleBackColor = false;
			this->btn_historialComp->Click += gcnew System::EventHandler(this, &Productos::btn_historialComp_Click);
			// 
			// Productos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(786, 412);
			this->Controls->Add(this->pB_flecha2);
			this->Controls->Add(this->btn_historialComp);
			this->Controls->Add(this->pb_flecha);
			this->Controls->Add(this->btn_compras);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel_shadowing);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Productos";
			this->Text = L"Productos";
			this->Load += gcnew System::EventHandler(this, &Productos::Productos_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_eliminar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_modificar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_prod))->EndInit();
			this->panel_headinfo2->ResumeLayout(false);
			this->panel_headinfo2->PerformLayout();
			this->panel_shadowing->ResumeLayout(false);
			this->panel_shadowing->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_agregarGrupo))->EndInit();
			this->panel_headinfo->ResumeLayout(false);
			this->panel_headinfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_flecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_flecha2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Productos_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se carga el placeholder del textbox de búsqueda
		this->tb_busqueda->Text = default_text;

		// Se carga el placeholder del textbox de la estructura de fecha de expiración
		this->tb_fexp->Text = fExp_structure;

		// Se carga una imagen que simula un botón para agregar grupo
		this->pb_agregarGrupo->Image = Image::FromFile("botonguardar.png");

		// Se carga una imagen que simula una lupa en el buscador
		this->pictureBox_buscar->Image = Image::FromFile("imagenbuscar.png");

		// Se carga una imagen que simula un botón para modificar productos
		this->pB_modificar->Image = Image::FromFile("botonmodificar.png");

		// Se carga una imagen que simula un botón para eliminar productos
		this->pB_eliminar->Image = Image::FromFile("botoneliminar.png");

		// Se carga una imagen que simula una flecha en el botón de realizar compras
		this->pb_flecha->Image = Image::FromFile("flechaclic.png");
		this->pB_flecha2->Image = Image::FromFile("flechaclic.png");

		// Se muestran las unidades de medida en un comboBox para su posible modificación
		string unitpath = "unidad de medida\\Unidades de medida registradas.txt";
		uMeasure::mostrarMedidas_ComboBox(unitpath, cb_umedida_despleg);
		
		// Se muestran los grupos disponibles
		archivoProducto::mostrarGrupos(cb_grupo_despleg);

		// Se llama a esta función para mostrar los productos registrados al momento de cargar el formulario
		archivoProducto::mostrarProductos(dgv_prod);

		// Se centran las siguientes columnas:
		dgv_prod->Columns["Ubicación"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		dgv_prod->Columns["U. Medida"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		dgv_prod->Columns["Existencias"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		dgv_prod->Columns["Exist. min."]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		dgv_prod->Columns["Precio unit."]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		dgv_prod->Columns["F. Exp"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		
		// Se aumenta el ancho de las siguientes columnas:
		dgv_prod->Columns["Descripción"]->Width = 160;
		dgv_prod->Columns["Ubicación"]->Width = 160;
	}
	// Por motivos de mayor entendimiento al registro, se darán indicaciones adicionales con texto como placeholders
	private: System::String^ default_text = "Haga click en la lupa para buscar productos por su código o descripción...";
	private: System::String^ fExp_structure = "dd/mm/aaaa";
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
	private: System::Void tb_fexp_Enter(System::Object^ sender, System::EventArgs^ e) {
		// Borra el texto predeterminado cuando el control TextBox obtiene el foco
		if (tb_fexp->Text == fExp_structure) {
			tb_fexp->Text = "";
			tb_fexp->ForeColor = SystemColors::WindowText;
			tb_fexp->ReadOnly = false;
			// Al obtener el foco cambiamos la fuente de texto a predeterminado
			tb_fexp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
		}
	}
	private: System::Void tb_fexp_Leave(System::Object^ sender, System::EventArgs^ e) {
		// Restaura el texto predeterminado si el usuario no ingresó nada
		if (this->tb_fexp->Text == "") {
			this->tb_fexp->Text = fExp_structure;
			this->tb_fexp->ForeColor = SystemColors::InactiveCaption;
			tb_fexp->ReadOnly = true;
			// Al momento de no interactuar con el textbox, se usa una fuente de texto personalizada con estilo itálico
			tb_fexp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic));
		}
	}
	private: System::Void btn_guardar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo inventario" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		int error = 0;
		// Redactamos algunos mensajes de error, al momento de validar las entradas
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";
		String^ desc_isSame = "La descripción de producto que desea añadir ya está registrada.";
		String^ emptyCbBox_Message = "Seleccione una opción válida.";
		String^ not_anInt = "Está trabajando con unidades. Debe de ingresar valores enteros positivos.";
		String^ not_aFloat = "Solo se permiten valores numéricos positivos.";
		String^ emptyTxtBox_Message2 = "Este campo es obligatorio, pero puede no rellenarlo ingresando cualquier caracter <<->>.";
		String^ emin_isGreaterthan_exist = "La cantidad de existencias mínimas no pueden sobrepasar a la cantidad actual de existencias a registrar.";

		// 1. Verificamos si los textBoxes o comboBoxes no están vacíos:
		validate::isComboBox_notEmpty(cb_grupo_despleg, errorProvider, emptyCbBox_Message, error);
		validate::isComboBox_notEmpty(cb_umedida_despleg, errorProvider, emptyCbBox_Message, error);
		validate::isDesc_thesame(tb_descripcion, errorProvider, desc_isSame, error);
		validate::isTxtBox_notEmpty(tb_ubic, errorProvider, emptyTxtBox_Message2, error);
		validate::isDate_correct(tb_fexp, errorProvider, true, error);

		// 2. Verificamos si algunos textBoxes son enteros o flotantes positivos
		if (cb_umedida_despleg->Text == "u") {
			validate::isTxtBox_posInt(tb_exist, errorProvider, not_anInt, error);
			validate::isTxtBox_posInt(tb_emin, errorProvider, not_anInt, error);
		}
		else {
			validate::isTxtBox_posFloat(tb_exist, errorProvider, not_aFloat, error);
			validate::isTxtBox_posFloat(tb_emin, errorProvider, not_aFloat, error);
		}
		validate::isTxtBox_posFloat(tb_pUnit, errorProvider, not_aFloat, error);

		if (error == 0) {
			// 3. Verificamos si las existencias mínimas son menores que las existencias a ingresar
			validate::isTxtBox_greaterThan(tb_exist, tb_emin, errorProvider, emin_isGreaterthan_exist, error);
		}

		// Si en alguna de las validaciones hubo errores en la entrada de datos, interrumpimos el proceso de modificación
		if (error > 0) {
			return;
		}

		// El usuario rellenó los datos de forma exitosa, procedemos al proceso de registro del producto
		// Se convierten todos los valores del formulario a espacio de nombres que C++ maneja (std)
		string group = conversion::to_stdstring(this->cb_grupo_despleg->Text);
		string desc = conversion::to_stdstring(this->tb_descripcion->Text);
		string uMeasure = conversion::to_stdstring(this->cb_umedida_despleg->Text);
		float exist = stof(conversion::to_stdstring(this->tb_exist->Text));
		float emin = stof(conversion::to_stdstring(this->tb_emin->Text));
		string ubic = conversion::to_stdstring(this->tb_ubic->Text);
		float pUnit = stof(conversion::to_stdstring(this->tb_pUnit->Text));
		string fExp = conversion::to_stdstring(this->tb_fexp->Text);

		// Se genera un código automático para representar al producto agregado
		string code = codigo::generarCodigo(group);

		// Se crea un MessageBox que avisará sobre el registro exitoso del proveedor en el archivo
		String^ messageText = "Su producto ha sido registrado exitosamente, identificándose con el siguiente código: " + gcnew String(code.c_str());
		String^ messageTitle = "Registro exitoso";
		MessageBoxButtons messageButtons = MessageBoxButtons::OK;
		MessageBoxIcon messageIcon = MessageBoxIcon::Information;
		MessageBox::Show(messageText, messageTitle, messageButtons, messageIcon);

		// Se guardan los respectivos datos en un archivo de texto (llamado desde el header archivarProveedores)
		archivoProducto::registrarProducto(code, group, desc, uMeasure, exist, emin, ubic, pUnit, fExp);

		// Al guardar los datos, se vacían las cajas de texto
		this->cb_grupo_despleg->Text = "";
		this->tb_descripcion->Text = "";
		this->cb_umedida_despleg->Text = "";
		this->tb_exist->Text = "";
		this->tb_emin->Text = "";
		this->tb_pUnit->Text = "";
		this->tb_ubic->Text = "";
		this->tb_fexp->Text = "";

		// Actualizamos el datagridview para que el cliente registrado se vea correctamente en la tabla
		archivoProducto::mostrarProductos(dgv_prod);
	}
	private: System::Void pictureBox_buscar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener el valor del TextBox
		String^ searchedDesc = this->tb_busqueda->Text;

		// Si no se ha ingresado nada en el buscador y aún así se quiere buscar, se lanzarán un mensaje de error
		if (searchedDesc == default_text || searchedDesc->Trim() == "") {
			MessageBox::Show("Debe de indicar la descripción de un producto para comenzar con la búsqueda. ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Stop);
		}
		else {
			/* Se llama a la función que tiene las instrucciones para la búsqueda en el datagridview y se pasan variables de información del producto...
			   ...para su posible obtención y manipulación*/
			archivoProducto::buscarProducto(dgv_prod, searchedDesc, found, codeProduct, groupProduct, descProduct, uMeasureProduct,
											existProduct, existminProduct, ubicProduct, pUnitProduct, fExpProduct);
		}
		this->tb_busqueda->Text = "";
	}
	private: System::Void pB_modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo inventario" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		/* El usuario decidió modificar el producto buscado; por lo que se crea una nueva instancia...
		...del formulario de Modificar_producto.h*/
		if (found == true) {
			// Creamos una nueva instancia del formulario Modificar_cliente.h
			Inventrack::Modificar_producto^ Modificar = gcnew Inventrack::Modificar_producto();
			// Para cada campo y textbox, se mostrarán una vista previa que el producto tiene
			Modificar->code = codeProduct;
			Modificar->group = groupProduct;
			Modificar->tb_desc->Text = descProduct;
			Modificar->cb_umedida->Text = uMeasureProduct;
			Modificar->tb_exist->Text = existProduct;
			Modificar->tb_fexp->Text = fExpProduct;
			Modificar->tb_min->Text = existminProduct;
			Modificar->tb_punit->Text = pUnitProduct;
			Modificar->tb_ubic->Text = ubicProduct;
			Modificar->ShowDialog();
			// Actualizamos el datagridview para mostrar automáticamente los cambios del proveedor
			archivoProducto::mostrarProductos(dgv_prod);
		}
		else {
			MessageBox::Show("Por favor, primero busque un producto para modificar sus datos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void pB_eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo inventario" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (found == true) {
			// El usuario decidio eliminar un productor; por tanto, se se le preguntará para validar la eliminación
			System::Windows::Forms::DialogResult result = MessageBox::Show("Eliminar este producto también eliminará todas las ventas asociadas con él. ¿Está seguro de que desea continuar? ", "Eliminar producto", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				string searchedCode = conversion::to_stdstring(codeProduct);
				string searchedGroup = conversion::to_stdstring(groupProduct);

				// Llamamos a la función que permitirá la eliminación del producto
				archivoProducto::eliminarProducto(searchedCode, searchedGroup);
				// Actualizamos los datos del datagridview
				archivoProducto::mostrarProductos(dgv_prod);
			}
		}
		else {
			MessageBox::Show("Por favor, primero busque un producto para poder eliminarlo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void pb_agregarGrupo_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo inventario" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.", 
							 "Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Creamos una nueva instancia del formulario "Agregar_grupo.h"
		Inventrack::Agregar_grupo^ AG = gcnew Inventrack::Agregar_grupo();
		AG->ShowDialog();

		// Actualizamos el comboBox de grupos en caso de agregarse uno
		cb_grupo_despleg->Items->Clear();
		archivoProducto::mostrarGrupos(cb_grupo_despleg);
	}
	private: System::Void btn_compras_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo inventario" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Creamos una nueva instancia del formulario "Compras.h"
		Inventrack::Compras^ Comp = gcnew Inventrack::Compras();
		Comp->Show();
	
		// Actualizamos la muestra de los productos luego de la compra efectuada
		archivoProducto::mostrarProductos(dgv_prod);
	}
	private: System::Void btn_historialComp_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se verifica si el usuario que accedió al sistema tiene permiso para interactuar en estos campos
		if (role != "Solo inventario" && role != "Administrador" && role != "Inventario y factura") {
			// De ser así, enviamos un mensaje de excepción e interrumpimos el proceso
			MessageBox::Show("Lo sentimos, por ahora usted no tiene permiso para realizar este proceso.",
				"Proceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Creamos una nueva instancia del formulario "Historial_compras.h"
		Inventrack::Historial_compras^ HComp = gcnew Inventrack::Historial_compras();
		HComp->Show();
	}
	};
}