#pragma once
#include "proveedores/archivarProveedores.h"
#include "Modificar_proveedor.h"
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
	/// Resumen de Proveedores
	/// </summary>
	public ref class Proveedores : public System::Windows::Forms::Form
	{
	public:
		Proveedores(void)
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
		~Proveedores()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox_buscar;
	private: System::Windows::Forms::TextBox^ tb_busqueda;
	private: System::Windows::Forms::DataGridView^ dataGridview_prov;
	private: System::Windows::Forms::Panel^ panel_headinfo2;
	private: System::Windows::Forms::Label^ lbl_verprov;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::Label^ lbl_ltrabajo;
	private: System::Windows::Forms::TextBox^ tb_tel;
	private: System::Windows::Forms::Label^ lbl_tel;
	private: System::Windows::Forms::TextBox^ tb_id;
	private: System::Windows::Forms::Label^ lbl_id;
	private: System::Windows::Forms::TextBox^ tb_surnames;
	private: System::Windows::Forms::Button^ btn_guardar;
	private: System::Windows::Forms::Label^ lbl_surnames;
	private: System::Windows::Forms::TextBox^ tb_names;
	private: System::Windows::Forms::Label^ lbl_names;
	private: System::Windows::Forms::Panel^ panel_headinfo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_registerprovider;
	private: System::Windows::Forms::TextBox^ tb_material;
	private: System::Windows::Forms::Label^ lbl_material;
	private: System::Windows::Forms::TextBox^ tb_ltrabajo;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pB_eliminar;
	private: System::Windows::Forms::PictureBox^ pB_modificar;
	
	// Declaramos variables que necesitan ser usadas en el formulario de "Modificar_proveedores", a fin de tener una vista previa de los datos originales
	public: String^ IDProv = "";
	public: String^ telProv = "";
	public: String^ namesProv = "";
	public: String^ surnamesProv = "";
	public: String^ worksiteProv = "";
	public: String^ materialProv = "";
	// Se declara una variable booleana que indicará si fue encontrado o no el proveedor buscado
	public: bool found;
	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	public:
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pB_eliminar = (gcnew System::Windows::Forms::PictureBox());
			this->pB_modificar = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_buscar = (gcnew System::Windows::Forms::PictureBox());
			this->tb_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->dataGridview_prov = (gcnew System::Windows::Forms::DataGridView());
			this->panel_headinfo2 = (gcnew System::Windows::Forms::Panel());
			this->lbl_verprov = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->tb_material = (gcnew System::Windows::Forms::TextBox());
			this->lbl_material = (gcnew System::Windows::Forms::Label());
			this->tb_ltrabajo = (gcnew System::Windows::Forms::TextBox());
			this->lbl_ltrabajo = (gcnew System::Windows::Forms::Label());
			this->tb_tel = (gcnew System::Windows::Forms::TextBox());
			this->lbl_tel = (gcnew System::Windows::Forms::Label());
			this->tb_id = (gcnew System::Windows::Forms::TextBox());
			this->lbl_id = (gcnew System::Windows::Forms::Label());
			this->tb_surnames = (gcnew System::Windows::Forms::TextBox());
			this->btn_guardar = (gcnew System::Windows::Forms::Button());
			this->lbl_surnames = (gcnew System::Windows::Forms::Label());
			this->tb_names = (gcnew System::Windows::Forms::TextBox());
			this->lbl_names = (gcnew System::Windows::Forms::Label());
			this->panel_headinfo = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_registerprovider = (gcnew System::Windows::Forms::Label());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_eliminar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_modificar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridview_prov))->BeginInit();
			this->panel_headinfo2->SuspendLayout();
			this->panel_shadowing->SuspendLayout();
			this->panel_headinfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::LightGray;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->pictureBox_buscar);
			this->panel1->Controls->Add(this->tb_busqueda);
			this->panel1->Controls->Add(this->dataGridview_prov);
			this->panel1->Controls->Add(this->panel_headinfo2);
			this->panel1->Location = System::Drawing::Point(5, 290);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(673, 426);
			this->panel1->TabIndex = 9;
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
			this->pB_eliminar->Click += gcnew System::EventHandler(this, &Proveedores::pB_eliminar_Click);
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
			this->pB_modificar->Click += gcnew System::EventHandler(this, &Proveedores::pB_modificar_Click);
			// 
			// pictureBox_buscar
			// 
			this->pictureBox_buscar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox_buscar->Location = System::Drawing::Point(416, 53);
			this->pictureBox_buscar->Name = L"pictureBox_buscar";
			this->pictureBox_buscar->Size = System::Drawing::Size(17, 17);
			this->pictureBox_buscar->TabIndex = 0;
			this->pictureBox_buscar->TabStop = false;
			this->pictureBox_buscar->Click += gcnew System::EventHandler(this, &Proveedores::pictureBox_buscar_Click);
			// 
			// tb_busqueda
			// 
			this->tb_busqueda->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_busqueda->Location = System::Drawing::Point(22, 51);
			this->tb_busqueda->Name = L"tb_busqueda";
			this->tb_busqueda->Size = System::Drawing::Size(413, 22);
			this->tb_busqueda->TabIndex = 8;
			this->tb_busqueda->Enter += gcnew System::EventHandler(this, &Proveedores::tb_busqueda_Enter);
			this->tb_busqueda->Leave += gcnew System::EventHandler(this, &Proveedores::tb_busqueda_Leave);
			// 
			// dataGridview_prov
			// 
			this->dataGridview_prov->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridview_prov->Location = System::Drawing::Point(15, 84);
			this->dataGridview_prov->Name = L"dataGridview_prov";
			this->dataGridview_prov->Size = System::Drawing::Size(641, 340);
			this->dataGridview_prov->TabIndex = 7;
			// 
			// panel_headinfo2
			// 
			this->panel_headinfo2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_headinfo2->Controls->Add(this->lbl_verprov);
			this->panel_headinfo2->Location = System::Drawing::Point(3, 5);
			this->panel_headinfo2->Name = L"panel_headinfo2";
			this->panel_headinfo2->Size = System::Drawing::Size(667, 33);
			this->panel_headinfo2->TabIndex = 6;
			// 
			// lbl_verprov
			// 
			this->lbl_verprov->AutoSize = true;
			this->lbl_verprov->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_verprov->Location = System::Drawing::Point(14, 7);
			this->lbl_verprov->Name = L"lbl_verprov";
			this->lbl_verprov->Size = System::Drawing::Size(184, 19);
			this->lbl_verprov->TabIndex = 0;
			this->lbl_verprov->Text = L"Ver y modificar proveedores";
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->tb_material);
			this->panel_shadowing->Controls->Add(this->lbl_material);
			this->panel_shadowing->Controls->Add(this->tb_ltrabajo);
			this->panel_shadowing->Controls->Add(this->lbl_ltrabajo);
			this->panel_shadowing->Controls->Add(this->tb_tel);
			this->panel_shadowing->Controls->Add(this->lbl_tel);
			this->panel_shadowing->Controls->Add(this->tb_id);
			this->panel_shadowing->Controls->Add(this->lbl_id);
			this->panel_shadowing->Controls->Add(this->tb_surnames);
			this->panel_shadowing->Controls->Add(this->btn_guardar);
			this->panel_shadowing->Controls->Add(this->lbl_surnames);
			this->panel_shadowing->Controls->Add(this->tb_names);
			this->panel_shadowing->Controls->Add(this->lbl_names);
			this->panel_shadowing->Controls->Add(this->panel_headinfo);
			this->panel_shadowing->Location = System::Drawing::Point(5, 6);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(673, 263);
			this->panel_shadowing->TabIndex = 8;
			this->panel_shadowing->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Proveedores::panel_shadowing_Paint_1);
			// 
			// tb_material
			// 
			this->tb_material->Location = System::Drawing::Point(437, 136);
			this->tb_material->Name = L"tb_material";
			this->tb_material->Size = System::Drawing::Size(190, 20);
			this->tb_material->TabIndex = 27;
			// 
			// lbl_material
			// 
			this->lbl_material->AutoSize = true;
			this->lbl_material->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_material->Location = System::Drawing::Point(375, 138);
			this->lbl_material->Name = L"lbl_material";
			this->lbl_material->Size = System::Drawing::Size(50, 15);
			this->lbl_material->TabIndex = 26;
			this->lbl_material->Text = L"Material";
			// 
			// tb_ltrabajo
			// 
			this->tb_ltrabajo->Location = System::Drawing::Point(129, 134);
			this->tb_ltrabajo->Name = L"tb_ltrabajo";
			this->tb_ltrabajo->Size = System::Drawing::Size(190, 20);
			this->tb_ltrabajo->TabIndex = 25;
			// 
			// lbl_ltrabajo
			// 
			this->lbl_ltrabajo->AutoSize = true;
			this->lbl_ltrabajo->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_ltrabajo->Location = System::Drawing::Point(30, 138);
			this->lbl_ltrabajo->Name = L"lbl_ltrabajo";
			this->lbl_ltrabajo->Size = System::Drawing::Size(93, 15);
			this->lbl_ltrabajo->TabIndex = 24;
			this->lbl_ltrabajo->Text = L"Lugar de trabajo";
			// 
			// tb_tel
			// 
			this->tb_tel->Location = System::Drawing::Point(437, 52);
			this->tb_tel->Name = L"tb_tel";
			this->tb_tel->Size = System::Drawing::Size(190, 20);
			this->tb_tel->TabIndex = 23;
			// 
			// lbl_tel
			// 
			this->lbl_tel->AutoSize = true;
			this->lbl_tel->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tel->Location = System::Drawing::Point(372, 54);
			this->lbl_tel->Name = L"lbl_tel";
			this->lbl_tel->Size = System::Drawing::Size(53, 15);
			this->lbl_tel->TabIndex = 22;
			this->lbl_tel->Text = L"Teléfono";
			// 
			// tb_id
			// 
			this->tb_id->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_id->Location = System::Drawing::Point(129, 52);
			this->tb_id->Name = L"tb_id";
			this->tb_id->Size = System::Drawing::Size(190, 22);
			this->tb_id->TabIndex = 21;
			this->tb_id->Enter += gcnew System::EventHandler(this, &Proveedores::tb_id_Enter);
			this->tb_id->Leave += gcnew System::EventHandler(this, &Proveedores::tb_id_Leave);
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_id->Location = System::Drawing::Point(80, 52);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(43, 15);
			this->lbl_id->TabIndex = 20;
			this->lbl_id->Text = L"Cédula";
			// 
			// tb_surnames
			// 
			this->tb_surnames->Location = System::Drawing::Point(437, 95);
			this->tb_surnames->Name = L"tb_surnames";
			this->tb_surnames->Size = System::Drawing::Size(190, 20);
			this->tb_surnames->TabIndex = 19;
			// 
			// btn_guardar
			// 
			this->btn_guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_guardar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_guardar->ForeColor = System::Drawing::Color::White;
			this->btn_guardar->Location = System::Drawing::Point(311, 195);
			this->btn_guardar->Name = L"btn_guardar";
			this->btn_guardar->Size = System::Drawing::Size(82, 33);
			this->btn_guardar->TabIndex = 18;
			this->btn_guardar->Text = L"Guardar";
			this->btn_guardar->UseVisualStyleBackColor = false;
			this->btn_guardar->Click += gcnew System::EventHandler(this, &Proveedores::btn_guardar_Click);
			// 
			// lbl_surnames
			// 
			this->lbl_surnames->AutoSize = true;
			this->lbl_surnames->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_surnames->Location = System::Drawing::Point(358, 97);
			this->lbl_surnames->Name = L"lbl_surnames";
			this->lbl_surnames->Size = System::Drawing::Size(67, 15);
			this->lbl_surnames->TabIndex = 8;
			this->lbl_surnames->Text = L"Apellido (s)";
			// 
			// tb_names
			// 
			this->tb_names->Location = System::Drawing::Point(129, 93);
			this->tb_names->Name = L"tb_names";
			this->tb_names->Size = System::Drawing::Size(190, 20);
			this->tb_names->TabIndex = 5;
			// 
			// lbl_names
			// 
			this->lbl_names->AutoSize = true;
			this->lbl_names->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_names->Location = System::Drawing::Point(56, 95);
			this->lbl_names->Name = L"lbl_names";
			this->lbl_names->Size = System::Drawing::Size(67, 15);
			this->lbl_names->TabIndex = 4;
			this->lbl_names->Text = L"Nombre (s)";
			// 
			// panel_headinfo
			// 
			this->panel_headinfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_headinfo->Controls->Add(this->label1);
			this->panel_headinfo->Controls->Add(this->label_registerprovider);
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
			// label_registerprovider
			// 
			this->label_registerprovider->AutoSize = true;
			this->label_registerprovider->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label_registerprovider->Location = System::Drawing::Point(10, 6);
			this->label_registerprovider->Name = L"label_registerprovider";
			this->label_registerprovider->Size = System::Drawing::Size(145, 19);
			this->label_registerprovider->TabIndex = 0;
			this->label_registerprovider->Text = L"Registrar proveedores";
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Proveedores
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(717, 451);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel_shadowing);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Proveedores";
			this->Text = L"Proveedores";
			this->Load += gcnew System::EventHandler(this, &Proveedores::Proveedores_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_eliminar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_modificar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridview_prov))->EndInit();
			this->panel_headinfo2->ResumeLayout(false);
			this->panel_headinfo2->PerformLayout();
			this->panel_shadowing->ResumeLayout(false);
			this->panel_shadowing->PerformLayout();
			this->panel_headinfo->ResumeLayout(false);
			this->panel_headinfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel_shadowing_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel_shadowing_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pictureBox_buscar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener el valor del TextBox
		String^ searchedID = this->tb_busqueda->Text;

		// Si no se ha ingresado nada en el buscador y aún así se quiere buscar, se lanzarán un mensaje de error
		if (searchedID == default_text || searchedID == "") {
			MessageBox::Show("Debe de indicar la cédula de un proveedor para comenzar con la búsqueda. ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Stop);
		}
		else {
			/* Se llama a la función que tiene las instrucciones para la búsqueda en el datagridview y se pasan variables de información del cliente...
			   ...para su posible obtención y manipulación*/
			archivoProveedores::buscarProveedor(dataGridview_prov, searchedID, found, IDProv, telProv, namesProv, surnamesProv, worksiteProv, materialProv);
		}
	}
	private: System::Void Proveedores_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se carga el placeholder del textbox de búsqueda
		this->tb_busqueda->Text = default_text;
		// Se carga el placeholder del textbox de cédula
		this->tb_id->Text = ID_Struct;

		// Se carga una imagen que simula una lupa en el buscador
		this->pictureBox_buscar->Image = Image::FromFile("imagenbuscar.png");

		// Se carga una imagen que simula un botón para modificar proveedores
		this->pB_modificar->Image = Image::FromFile("botonmodificar.png");

		// Se carga una imagen que simula un botón para eliminar proveedores
		this->pB_eliminar->Image = Image::FromFile("botoneliminar.png");

		// Se llama a esta función para mostrar los proveedores registrados al momento de cargar el formulario
		archivoProveedores::mostrarProveedores(dataGridview_prov);

		// Se centran los encabezados del datagridview
		dataGridview_prov->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		dataGridview_prov->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		// Se aumenta el ancho de las siguientes columnas:
		dataGridview_prov->Columns["Nombres"]->Width = 120;
		dataGridview_prov->Columns["Apellidos"]->Width = 120;
		dataGridview_prov->Columns["Lugar de trabajo"]->Width = 200;
		dataGridview_prov->Columns["Material"]->Width = 120;
	}
	// Por motivos de mayor entendimiento al registro, se darán indicaciones adicionales con texto como placeholders
	private: System::String^ default_text = "Haga click en la lupa para buscar proveedores...";

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
	private: System::Void btn_guardar_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";
		String^ ID_isSame = "La cédula del proveedor que desea añadir ya está registrada.";
		// Se realizan validaciones antes del registro de los datos del producto:

		// 1. Verificamos si los textBoxes no están vacíos:
		validate::isID_thesame(tb_id, "proveedores\\Registro de proveedores.txt", errorProvider, ID_isSame, error); // Verificamos si la ID a registrar es la misma a cualquiera contenida en el archivo de registro
		validate::isTxtBox_notEmpty(tb_tel, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_names, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_surnames, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_ltrabajo, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_material, errorProvider, emptyTxtBox_Message, error);

		// Si en alguna de las validaciones hubo errores en la entrada de datos, interrumpimos el proceso de registro
		if (error > 0) {
			return;
		}

		// El usuario rellenó los datos de forma exitosa, procedemos al proceso de registro del proveedor
		// Se convierten todos los valores del formulario a espacio de nombres que C++ maneja (std)
		string ID = conversion::to_stdstring(this->tb_id-> Text);
		string telProv = conversion::to_stdstring(this->tb_tel->Text);
		string nomProv = conversion::to_stdstring(this->tb_names->Text);
		string surnProv = conversion::to_stdstring(this->tb_surnames->Text);
		string workSite = conversion::to_stdstring(this->tb_ltrabajo->Text);
		string material = conversion::to_stdstring(this->tb_material->Text);

		// Se guardan los respectivos datos en un archivo de texto (llamado desde el header archivarProveedores)
		archivoProveedores::registrarProveedores(ID, telProv, nomProv, surnProv, workSite, material);
		
		// Se crea un MessageBox que avisará sobre el registro exitoso del proveedor en el archivo
		String^ messageText = "Proveedor registrado con éxito.";
		String^ messageTitle = "Registro exitoso";
		MessageBoxButtons messageButtons = MessageBoxButtons::OK;
		MessageBoxIcon messageIcon = MessageBoxIcon::Information;
		MessageBox::Show(messageText, messageTitle, messageButtons, messageIcon);

		// Al guardar los datos, se vacían las cajas de texto
		this->tb_id->Text = "";
		this->tb_tel->Text = "";
		this->tb_names->Text = "";
		this->tb_surnames->Text = "";
		this->tb_ltrabajo->Text = "";
		this->tb_material->Text = "";

		// Actualizamos el datagridview para que el cliente registrado se vea correctamente en la tabla
		archivoProveedores::mostrarProveedores(dataGridview_prov);
	}
	private: System::Void pB_modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		/* El usuario decidió modificar el proveedor buscado; por lo que se crea una nueva instancia...
		...del formulario de Modificar_proveedor.h*/

		if (found == true) {
			// Creamos una nueva instancia del formulario Modificar_cliente.h
			Inventrack::Modificar_proveedor^ Modificar = gcnew Inventrack::Modificar_proveedor();
			// Para cada campo y textbox, se mostrarán una vista previa que el proveedor tiene
			Modificar->ced = IDProv;
			Modificar->tb_id->Text = IDProv;
			Modificar->tb_tel->Text = telProv;
			Modificar->tb_names->Text = namesProv;
			Modificar->tb_surn->Text = surnamesProv;
			Modificar->tb_worksite->Text = worksiteProv;
			Modificar->tb_material->Text = materialProv;
			Modificar->ShowDialog();
			// Actualizamos el datagridview para mostrar automáticamente los cambios del proveedor
			archivoProveedores::mostrarProveedores(dataGridview_prov);
		}
		else {
			MessageBox::Show("Por favor, primero busque un proveedor para modificar sus datos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void pB_eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (found == true) {
			// El usuario decidio eliminar un proveedor por tanto, se se le preguntará para validar la eliminación
			System::Windows::Forms::DialogResult result = MessageBox::Show("¿Está seguro de que desea eliminar este proveedor?", "Eliminar cliente", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				string ID = conversion::to_stdstring(IDProv);

				// Llamamos a la función que permitirá la eliminación del proveedor
				archivoProveedores::eliminarProveedor(ID);
				// Actualizamos los datos del datagridview
				archivoProveedores::mostrarProveedores(dataGridview_prov);
			}
		}
		else {
			MessageBox::Show("Por favor, primero busque un cliente para poder eliminarlo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	// Se hace un placeholder para indicar la estructura de la cédula nicaragüense
	private: System::String^ ID_Struct = "NNN-NNNNNN-NNNNL";

	private: System::Void tb_id_Enter(System::Object^ sender, System::EventArgs^ e) {
		// Borra el texto predeterminado cuando el control TextBox obtiene el foco
		if (tb_id->Text == ID_Struct) {
			tb_id->Text = "";
			tb_id->ForeColor = SystemColors::WindowText;
			tb_id->ReadOnly = false;
			// Al obtener el foco cambiamos la fuente de texto a predeterminado
			tb_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
		}
	}
	private: System::Void tb_id_Leave(System::Object^ sender, System::EventArgs^ e) {
		// Restaura el texto predeterminado si el usuario no ingresó nada
		if (this->tb_id->Text == "") {
			this->tb_id->Text = ID_Struct;
			this->tb_id->ForeColor = SystemColors::InactiveCaption;
			// Al momento de no interactuar con el textbox, se usa una fuente de texto personalizada con estilo itálico
			tb_id->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic));
			tb_id->ReadOnly = true;
		}
	}
	};
}