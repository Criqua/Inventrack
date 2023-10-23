#pragma once
#include "SystemString_toStdString.h"
#include "factura/archivar_datosFactura.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historial_factura
	/// </summary>
	public ref class Historial_factura : public System::Windows::Forms::Form
	{
	public:
		Historial_factura(void)
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
		~Historial_factura()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_fondo;
	private: System::Windows::Forms::PictureBox^ pB_buscar;
	protected:
	private: System::Windows::Forms::TextBox^ tb_busqueda;
	public: System::Windows::Forms::DataGridView^ dgv_facturas;
	private:
	private:
	private: System::Windows::Forms::Panel^ panel6;
	public:
	private: System::Windows::Forms::PictureBox^ pB_anular;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ lbl_historial;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::PictureBox^ pB_ver;
	// Declaramos variables que necesitan ser usadas para anular una factura
	public: String^ numFactura = "";
	public: String^ fEmision = "";
	public: String^ clientInitials = "";
    // Se declara una variable booleana que indicará si fue encontrado o no la factura buscada
	public: bool found;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel_fondo = (gcnew System::Windows::Forms::Panel());
			this->pB_buscar = (gcnew System::Windows::Forms::PictureBox());
			this->tb_busqueda = (gcnew System::Windows::Forms::TextBox());
			this->dgv_facturas = (gcnew System::Windows::Forms::DataGridView());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pB_ver = (gcnew System::Windows::Forms::PictureBox());
			this->pB_anular = (gcnew System::Windows::Forms::PictureBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbl_historial = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel_fondo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_buscar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_facturas))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_ver))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_anular))->BeginInit();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_fondo
			// 
			this->panel_fondo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_fondo->BackColor = System::Drawing::Color::LightGray;
			this->panel_fondo->Controls->Add(this->pB_buscar);
			this->panel_fondo->Controls->Add(this->tb_busqueda);
			this->panel_fondo->Controls->Add(this->dgv_facturas);
			this->panel_fondo->Controls->Add(this->panel6);
			this->panel_fondo->Controls->Add(this->panel5);
			this->panel_fondo->Location = System::Drawing::Point(5, 4);
			this->panel_fondo->Name = L"panel_fondo";
			this->panel_fondo->Size = System::Drawing::Size(737, 498);
			this->panel_fondo->TabIndex = 9;
			// 
			// pB_buscar
			// 
			this->pB_buscar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pB_buscar->Location = System::Drawing::Point(415, 54);
			this->pB_buscar->Name = L"pB_buscar";
			this->pB_buscar->Size = System::Drawing::Size(17, 17);
			this->pB_buscar->TabIndex = 12;
			this->pB_buscar->TabStop = false;
			this->pB_buscar->Click += gcnew System::EventHandler(this, &Historial_factura::pB_buscar_Click);
			// 
			// tb_busqueda
			// 
			this->tb_busqueda->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_busqueda->Location = System::Drawing::Point(22, 52);
			this->tb_busqueda->Name = L"tb_busqueda";
			this->tb_busqueda->Size = System::Drawing::Size(413, 22);
			this->tb_busqueda->TabIndex = 14;
			this->tb_busqueda->Enter += gcnew System::EventHandler(this, &Historial_factura::tb_busqueda_Enter);
			this->tb_busqueda->Leave += gcnew System::EventHandler(this, &Historial_factura::tb_busqueda_Leave);
			// 
			// dgv_facturas
			// 
			this->dgv_facturas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_facturas->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgv_facturas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_facturas->Location = System::Drawing::Point(9, 90);
			this->dgv_facturas->Name = L"dgv_facturas";
			this->dgv_facturas->Size = System::Drawing::Size(721, 400);
			this->dgv_facturas->TabIndex = 13;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->pB_ver);
			this->panel6->Controls->Add(this->pB_anular);
			this->panel6->Location = System::Drawing::Point(439, 52);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(45, 22);
			this->panel6->TabIndex = 17;
			// 
			// pB_ver
			// 
			this->pB_ver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pB_ver->Location = System::Drawing::Point(4, 3);
			this->pB_ver->Name = L"pB_ver";
			this->pB_ver->Size = System::Drawing::Size(15, 15);
			this->pB_ver->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_ver->TabIndex = 16;
			this->pB_ver->TabStop = false;
			this->pB_ver->Click += gcnew System::EventHandler(this, &Historial_factura::pB_ver_Click);
			// 
			// pB_anular
			// 
			this->pB_anular->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pB_anular->Location = System::Drawing::Point(24, 3);
			this->pB_anular->Name = L"pB_anular";
			this->pB_anular->Size = System::Drawing::Size(14, 14);
			this->pB_anular->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pB_anular->TabIndex = 15;
			this->pB_anular->TabStop = false;
			this->pB_anular->Click += gcnew System::EventHandler(this, &Historial_factura::pB_anular_Click);
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->lbl_historial);
			this->panel5->Controls->Add(this->label13);
			this->panel5->Location = System::Drawing::Point(3, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(731, 37);
			this->panel5->TabIndex = 1;
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
			this->lbl_historial->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_historial->Location = System::Drawing::Point(10, 9);
			this->lbl_historial->Name = L"lbl_historial";
			this->lbl_historial->Size = System::Drawing::Size(135, 19);
			this->lbl_historial->TabIndex = 0;
			this->lbl_historial->Text = L"Historial de facturas";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 2;
			// 
			// Historial_factura
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 506);
			this->Controls->Add(this->panel_fondo);
			this->Name = L"Historial_factura";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Historial de facturas";
			this->Load += gcnew System::EventHandler(this, &Historial_factura::Historial_factura_Load);
			this->panel_fondo->ResumeLayout(false);
			this->panel_fondo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_buscar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_facturas))->EndInit();
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_ver))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_anular))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Historial_factura_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargamos el placeholder del texto que se mostrará en el TextBox de búsqueda
		this->tb_busqueda->Text = default_text;

		// Se carga una imagen que simula un botón para buscar facturas
		this->pB_buscar->Image = Image::FromFile("imagenbuscar.png");

		// Se carga una imagen que simula un botón para ver facturas
		this->pB_ver->Image = Image::FromFile("botonver.png");

		// Se carga una imagen que simula un botón para anular facturas
		this->pB_anular->Image = Image::FromFile("botonanular.png");

		// Mostramos los datos finales de facturas almacenados en el archivo de texto Historial de facturas.txt
		archivoFactura::mostrar_historialFacturas(dgv_facturas);
	}
	// Por motivos de mayor entendimiento al registro, se darán indicaciones adicionales con texto como placeholders
	private: System::String^ default_text = "Haga click en la lupa para buscar facturas por código...";
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
	private: System::Void pB_buscar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se obtiene el valor del TextBox de búsqueda
		String^ searchedBill = this->tb_busqueda->Text;

		// Si no se ha ingresado nada en el buscador y aún así se quiere buscar, se lanzarán un mensaje de error
		if (searchedBill == default_text || searchedBill->Trim() == "") {
			MessageBox::Show("Debe de indicar el código de una factura para comenzar con la búsqueda. ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Stop);
		}
		else {
			/* Se llama a la función que tiene las instrucciones para la búsqueda en el datagridview y se pasan variables de información de factura...
			   ...para su posible obtención y vista*/
			archivoFactura::buscarFactura(dgv_facturas, searchedBill, numFactura, found, clientInitials, fEmision);
		}
		this->tb_busqueda->Text = "";
	}
	private: System::Void pB_anular_Click(System::Object^ sender, System::EventArgs^ e) {
		// Anular una factura
		// Convertimos los valores de System::String a std::string
		string nFac = conversion::to_stdstring(numFactura);
		string cInitials = conversion::to_stdstring(clientInitials);
		string fEmit = conversion::to_stdstring(fEmision);

		if (found == true) {
			// El usuario decidio anular una factura; por tanto, se se le preguntará para validar la eliminación
			System::Windows::Forms::DialogResult result = MessageBox::Show("¿Está seguro de que desea anular esta factura? ", "Anular factura", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				// Llamamos a la función que se encargará de anular la factura y devolver las mercancías al inventario nuevamente
				archivoFactura::anularFactura(nFac, cInitials, fEmit);
				// Como se anuló la factura, refrescamos la vista del historial:
				archivoFactura::mostrar_historialFacturas(dgv_facturas);
			}
		}
		else {
			MessageBox::Show("Por favor, primero busque una factura para poder anularla", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void pB_ver_Click(System::Object^ sender, System::EventArgs^ e) {
		if (found == true) {
			// Se crea un TextBox para mostrar el contenido del archivo
			TextBox^ textBox = gcnew TextBox();
			textBox->Multiline = true;
			textBox->Dock = DockStyle::Fill;

			// Se cambia la fuente del TextBox a Consolas 11
			textBox->Font = gcnew System::Drawing::Font("Consolas", 11);
			// No le permitimos al usuario que modifique lo contenido en el textbox
			textBox->ReadOnly = true;

			// Mostramos el nombre del archivo de texto del recibo como título del formulario
			String^ billfile_name = numFactura + "_" + clientInitials + "_" + fEmision;

			// Convertimos los valores de System::String a std::string
			string nFac = conversion::to_stdstring(numFactura);
			string cInitials = conversion::to_stdstring(clientInitials);
			string fEmit = conversion::to_stdstring(fEmision);

			// Mostramos el contenido del archivo en el TextBox
			archivoFactura::verFactura(nFac, cInitials, fEmit, textBox);

			// Se crea un formulario para mostrar el TextBox
			Form^ form = gcnew Form();
			form->Text = "Contenido del archivo: " + billfile_name;
			form->Size = System::Drawing::Size(950, 650);
			form->StartPosition = FormStartPosition::CenterScreen;
			form->Controls->Add(textBox);

			// Mostrammos el formulario
			form->ShowDialog();
		}
		else {
			MessageBox::Show("Por favor, primero busque una factura para poder visualizar su contenido", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}