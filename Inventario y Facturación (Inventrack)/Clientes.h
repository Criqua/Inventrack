#pragma once
#include "clientes/archivarClientes.h"
#include "SystemString_toStdString.h"
#include "Modificar_cliente.h"
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
	/// Resumen de Clientes
	/// </summary>
	public ref class Clientes : public System::Windows::Forms::Form
	{
	public:
		Clientes(void)
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
		~Clientes()
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
	private: System::Windows::Forms::DataGridView^ dataGridview_clients;
	private: System::Windows::Forms::Panel^ panel_headinfo2;
	private: System::Windows::Forms::Label^ lbl_verclient;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::Button^ btn_guardar;
	private: System::Windows::Forms::Label^ lbl_tel;
	private: System::Windows::Forms::TextBox^ tb_id;
	private: System::Windows::Forms::Label^ lbl_id;
	private: System::Windows::Forms::Panel^ panel_headinfo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_registerclient;
	private: System::Windows::Forms::Label^ lbl_n;
	private: System::Windows::Forms::TextBox^ tb_tel;
	private: System::Windows::Forms::Label^ lbl_surn;
	private: System::Windows::Forms::TextBox^ tb_name;
	private: System::Windows::Forms::TextBox^ tb_surname;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pB_modificar;
	private: System::Windows::Forms::PictureBox^ pB_eliminar;
	
	// Declaramos variables que necesitan ser usadas en el formulario de "Modificar_clientes", a fin de tener una vista previa de los datos originales
	public: String^ IDClient = "";
	public: String^ telClient = "";
	public: String^ namesClient = "";
	public: String^ surnamesClient = "";
	// Se declara una variable booleana que indicará si fue encontrado o no el cliente buscado
	public: bool found;

	private: System::Windows::Forms::ErrorProvider^ errorProvider;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pB_eliminar = (gcnew System::Windows::Forms::PictureBox());
			this->pB_modificar = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_buscar = (gcnew System::Windows::Forms::PictureBox());
			this->tb_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->dataGridview_clients = (gcnew System::Windows::Forms::DataGridView());
			this->panel_headinfo2 = (gcnew System::Windows::Forms::Panel());
			this->lbl_verclient = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->tb_surname = (gcnew System::Windows::Forms::TextBox());
			this->lbl_surn = (gcnew System::Windows::Forms::Label());
			this->tb_name = (gcnew System::Windows::Forms::TextBox());
			this->lbl_n = (gcnew System::Windows::Forms::Label());
			this->tb_tel = (gcnew System::Windows::Forms::TextBox());
			this->btn_guardar = (gcnew System::Windows::Forms::Button());
			this->lbl_tel = (gcnew System::Windows::Forms::Label());
			this->tb_id = (gcnew System::Windows::Forms::TextBox());
			this->lbl_id = (gcnew System::Windows::Forms::Label());
			this->panel_headinfo = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_registerclient = (gcnew System::Windows::Forms::Label());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_eliminar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_modificar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridview_clients))->BeginInit();
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
			this->panel1->Controls->Add(this->dataGridview_clients);
			this->panel1->Controls->Add(this->panel_headinfo2);
			this->panel1->Location = System::Drawing::Point(5, 237);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(673, 426);
			this->panel1->TabIndex = 7;
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
			this->panel2->TabIndex = 12;
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
			this->pB_eliminar->Click += gcnew System::EventHandler(this, &Clientes::pB_eliminar_Click);
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
			this->pB_modificar->Click += gcnew System::EventHandler(this, &Clientes::pB_modificar_Click);
			// 
			// pictureBox_buscar
			// 
			this->pictureBox_buscar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox_buscar->Location = System::Drawing::Point(416, 53);
			this->pictureBox_buscar->Name = L"pictureBox_buscar";
			this->pictureBox_buscar->Size = System::Drawing::Size(17, 17);
			this->pictureBox_buscar->TabIndex = 0;
			this->pictureBox_buscar->TabStop = false;
			this->pictureBox_buscar->Click += gcnew System::EventHandler(this, &Clientes::pictureBox_buscar_Click);
			// 
			// tb_busqueda
			// 
			this->tb_busqueda->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_busqueda->Location = System::Drawing::Point(22, 51);
			this->tb_busqueda->Name = L"tb_busqueda";
			this->tb_busqueda->Size = System::Drawing::Size(413, 22);
			this->tb_busqueda->TabIndex = 8;
			this->tb_busqueda->TextChanged += gcnew System::EventHandler(this, &Clientes::tb_busqueda_TextChanged);
			this->tb_busqueda->Enter += gcnew System::EventHandler(this, &Clientes::tb_busqueda_Enter);
			this->tb_busqueda->Leave += gcnew System::EventHandler(this, &Clientes::tb_busqueda_Leave);
			// 
			// dataGridview_clients
			// 
			this->dataGridview_clients->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridview_clients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridview_clients->Location = System::Drawing::Point(15, 84);
			this->dataGridview_clients->Name = L"dataGridview_clients";
			this->dataGridview_clients->Size = System::Drawing::Size(642, 340);
			this->dataGridview_clients->TabIndex = 7;
			// 
			// panel_headinfo2
			// 
			this->panel_headinfo2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_headinfo2->Controls->Add(this->lbl_verclient);
			this->panel_headinfo2->Location = System::Drawing::Point(3, 5);
			this->panel_headinfo2->Name = L"panel_headinfo2";
			this->panel_headinfo2->Size = System::Drawing::Size(667, 33);
			this->panel_headinfo2->TabIndex = 6;
			// 
			// lbl_verclient
			// 
			this->lbl_verclient->AutoSize = true;
			this->lbl_verclient->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_verclient->Location = System::Drawing::Point(14, 7);
			this->lbl_verclient->Name = L"lbl_verclient";
			this->lbl_verclient->Size = System::Drawing::Size(156, 19);
			this->lbl_verclient->TabIndex = 0;
			this->lbl_verclient->Text = L"Ver y modificar clientes";
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->tb_surname);
			this->panel_shadowing->Controls->Add(this->lbl_surn);
			this->panel_shadowing->Controls->Add(this->tb_name);
			this->panel_shadowing->Controls->Add(this->lbl_n);
			this->panel_shadowing->Controls->Add(this->tb_tel);
			this->panel_shadowing->Controls->Add(this->btn_guardar);
			this->panel_shadowing->Controls->Add(this->lbl_tel);
			this->panel_shadowing->Controls->Add(this->tb_id);
			this->panel_shadowing->Controls->Add(this->lbl_id);
			this->panel_shadowing->Controls->Add(this->panel_headinfo);
			this->panel_shadowing->Location = System::Drawing::Point(5, 5);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(673, 218);
			this->panel_shadowing->TabIndex = 6;
			this->panel_shadowing->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Clientes::panel_shadowing_Paint);
			// 
			// tb_surname
			// 
			this->tb_surname->Location = System::Drawing::Point(416, 95);
			this->tb_surname->Name = L"tb_surname";
			this->tb_surname->Size = System::Drawing::Size(190, 20);
			this->tb_surname->TabIndex = 23;
			// 
			// lbl_surn
			// 
			this->lbl_surn->AutoSize = true;
			this->lbl_surn->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_surn->Location = System::Drawing::Point(340, 97);
			this->lbl_surn->Name = L"lbl_surn";
			this->lbl_surn->Size = System::Drawing::Size(67, 15);
			this->lbl_surn->TabIndex = 22;
			this->lbl_surn->Text = L"Apellido (s)";
			// 
			// tb_name
			// 
			this->tb_name->Location = System::Drawing::Point(121, 95);
			this->tb_name->Name = L"tb_name";
			this->tb_name->Size = System::Drawing::Size(190, 20);
			this->tb_name->TabIndex = 21;
			// 
			// lbl_n
			// 
			this->lbl_n->AutoSize = true;
			this->lbl_n->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_n->Location = System::Drawing::Point(45, 97);
			this->lbl_n->Name = L"lbl_n";
			this->lbl_n->Size = System::Drawing::Size(67, 15);
			this->lbl_n->TabIndex = 20;
			this->lbl_n->Text = L"Nombre (s)";
			this->lbl_n->Click += gcnew System::EventHandler(this, &Clientes::lbl_n_Click);
			// 
			// tb_tel
			// 
			this->tb_tel->Location = System::Drawing::Point(416, 54);
			this->tb_tel->Name = L"tb_tel";
			this->tb_tel->Size = System::Drawing::Size(190, 20);
			this->tb_tel->TabIndex = 19;
			this->tb_tel->TextChanged += gcnew System::EventHandler(this, &Clientes::textBox1_TextChanged);
			// 
			// btn_guardar
			// 
			this->btn_guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_guardar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_guardar->ForeColor = System::Drawing::Color::White;
			this->btn_guardar->Location = System::Drawing::Point(288, 155);
			this->btn_guardar->Name = L"btn_guardar";
			this->btn_guardar->Size = System::Drawing::Size(82, 33);
			this->btn_guardar->TabIndex = 18;
			this->btn_guardar->Text = L"Guardar";
			this->btn_guardar->UseVisualStyleBackColor = false;
			this->btn_guardar->Click += gcnew System::EventHandler(this, &Clientes::btn_guardar_Click);
			// 
			// lbl_tel
			// 
			this->lbl_tel->AutoSize = true;
			this->lbl_tel->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tel->Location = System::Drawing::Point(354, 56);
			this->lbl_tel->Name = L"lbl_tel";
			this->lbl_tel->Size = System::Drawing::Size(53, 15);
			this->lbl_tel->TabIndex = 8;
			this->lbl_tel->Text = L"Teléfono";
			// 
			// tb_id
			// 
			this->tb_id->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_id->Location = System::Drawing::Point(121, 54);
			this->tb_id->Name = L"tb_id";
			this->tb_id->Size = System::Drawing::Size(190, 22);
			this->tb_id->TabIndex = 5;
			this->tb_id->TextChanged += gcnew System::EventHandler(this, &Clientes::tb_id_TextChanged);
			this->tb_id->Enter += gcnew System::EventHandler(this, &Clientes::tb_id_Enter);
			this->tb_id->Leave += gcnew System::EventHandler(this, &Clientes::tb_id_Leave);
			// 
			// lbl_id
			// 
			this->lbl_id->AutoSize = true;
			this->lbl_id->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_id->Location = System::Drawing::Point(69, 56);
			this->lbl_id->Name = L"lbl_id";
			this->lbl_id->Size = System::Drawing::Size(43, 15);
			this->lbl_id->TabIndex = 4;
			this->lbl_id->Text = L"Cédula";
			// 
			// panel_headinfo
			// 
			this->panel_headinfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel_headinfo->Controls->Add(this->label1);
			this->panel_headinfo->Controls->Add(this->label_registerclient);
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
			// label_registerclient
			// 
			this->label_registerclient->AutoSize = true;
			this->label_registerclient->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->label_registerclient->Location = System::Drawing::Point(10, 6);
			this->label_registerclient->Name = L"label_registerclient";
			this->label_registerclient->Size = System::Drawing::Size(117, 19);
			this->label_registerclient->TabIndex = 0;
			this->label_registerclient->Text = L"Registrar clientes";
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Clientes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(717, 451);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel_shadowing);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Clientes";
			this->Text = L"Clientes";
			this->Load += gcnew System::EventHandler(this, &Clientes::Clientes_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_eliminar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_modificar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_buscar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridview_clients))->EndInit();
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
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Clientes_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se carga el placeholder del textbox de búsqueda
		this->tb_busqueda->Text = default_text;
		// Se carga el placeholder del textbox de cédula
		this->tb_id->Text = ID_Struct;
		// Se carga una imagen que simula una lupa en el buscador
		this->pictureBox_buscar->Image = Image::FromFile("imagenbuscar.png");

		// Se carga una imagen que simula un botón para modificar clientes
		this->pB_modificar->Image = Image::FromFile("botonmodificar.png");

		// Se carga una imagen que simula un botón para eliminar clientes
		this->pB_eliminar->Image = Image::FromFile("botoneliminar.png");

		// Se llama a esta función para mostrar los clientes registrados al momento de cargar el formulario
		archivoCliente::mostrarClientes(dataGridview_clients);

		// Se centran los encabezados del datagridview
		dataGridview_clients->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
		dataGridview_clients->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
	}
	private: System::Void pictureBox_buscar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener el valor del TextBox
		String^ searchedID = this->tb_busqueda->Text;

		// Si no se ha ingresado nada en el buscador y aún así se quiere buscar, se lanzarán un mensaje de error
		if (searchedID == default_text || searchedID == "") {
			MessageBox::Show("Debe de indicar la cédula de un proveedor para comenzar con la búsqueda. ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Stop);
		}else {
			/* Se llama a la función que tiene las instrucciones para la búsqueda en el datagridview y se pasan variables de información del cliente...
			   ...para su posible obtención y manipulación*/
			archivoCliente::buscarCliente(dataGridview_clients, searchedID, found, IDClient, telClient, namesClient, surnamesClient);
		}
	}
	private: System::Void lbl_n_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_guardar_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";
		String^ ID_isSame = "La cédula del cliente que desea añadir ya está registrada.";
		// Se realizan validaciones antes del registro de los datos del cliente:

		// 1. Verificamos si los textBoxes no están vacíos:
		validate::isID_thesame(tb_id, "clientes\\Registro de clientes.txt", errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_tel, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_name, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_surname, errorProvider, emptyTxtBox_Message, error);
		
		// Si en alguna de las validaciones hubo errores en la entrada de datos, interrumpimos el proceso de registro
		if (error > 0) {
			return;
		}

		// El usuario rellenó los datos de forma exitosa, procedemos al proceso de registro del cliente
		// Se convierten todos los valores del formulario a espacio de nombres que C++ maneja (std)
		string ID = conversion::to_stdstring(this->tb_id->Text);
		string telNumb = conversion::to_stdstring(this->tb_tel->Text);
		string names = conversion::to_stdstring(this->tb_name->Text);
		string surnames = conversion::to_stdstring(this->tb_surname->Text);

		// Se guardan los respectivos datos en un archivo de texto (llamado desde el header archivarClientes)
		archivoCliente::registrarCliente(ID, telNumb, names, surnames);

		// Se crea un MessageBox que avisará sobre el registro exitoso del cliente en el archivo
		String^ messageText = "Cliente registrado con éxito.";
		String^ messageTitle = "Registro exitoso";
		MessageBoxButtons messageButtons = MessageBoxButtons::OK;
		MessageBoxIcon messageIcon = MessageBoxIcon::Information;
		MessageBox::Show(messageText, messageTitle, messageButtons, messageIcon);

		// Al guardar los datos, se vacían las cajas de texto
		this->tb_id->Text = "";
		this->tb_tel->Text = "";
		this->tb_name->Text = "";
		this->tb_surname->Text = "";

		// Actualizamos el datagridview para que el cliente registrado se vea correctamente en la tabla
		archivoCliente::mostrarClientes(dataGridview_clients);
	}
	private: System::Void pB_modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		/* El usuario decidió modificar el cliente buscado; por lo que se crea una nueva instancia...
		...del formulario de Modificar_cliente.h*/

		if (found == true) {
			// Creamos una nueva instancia del formulario Modificar_cliente.h
			Inventrack::Modificar_cliente^ Modificar = gcnew Inventrack::Modificar_cliente();
			// Para cada campo y textbox, se mostrarán una vista previa que el cliente tiene
			Modificar->oldID = IDClient;
			Modificar->tb_cedula->Text = IDClient;
			Modificar->tb_tel->Text = telClient;
			Modificar->tb_nombres->Text = namesClient;
			Modificar->tb_apellidos->Text = surnamesClient;
			Modificar->ShowDialog();
			// Actualizamos el datagridview para mostrar automáticamente los cambios del cliente
			archivoCliente::mostrarClientes(dataGridview_clients);
		}
		else {
			MessageBox::Show("Por favor, primero busque un producto para modificar sus datos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void pB_eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (found == true) {
			// El usuario decidio eliminar un cliente por tanto, se se le preguntará para validar la eliminación
			System::Windows::Forms::DialogResult result = MessageBox::Show("Eliminar este cliente también eliminará todas las ventas asociadas con él. ¿Está seguro de que desea continuar?", "Eliminar cliente", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				string ID = conversion::to_stdstring(IDClient);

				// Llamamos a la función que permitirá la eliminación del cliente
				archivoCliente::eliminarClientes(ID);
				// Actualizamos los datos del datagridview
				archivoCliente::mostrarClientes(dataGridview_clients);
			}
		}
		else {
			MessageBox::Show("Por favor, primero busque un cliente para poder eliminarlo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	// Por motivos de mayor entendimiento al registro, se darán indicaciones adicionales con texto como placeholders
	private: System::String^ default_text = "Haga click en la lupa para buscar clientes...";

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
	private: System::Void tb_busqueda_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tb_id_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
