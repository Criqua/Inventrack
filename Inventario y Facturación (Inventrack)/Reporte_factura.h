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
	/// Resumen de Reporte_factura
	/// </summary>
	public ref class Reporte_factura : public System::Windows::Forms::Form
	{
	public:
		Reporte_factura(void)
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
		~Reporte_factura()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_fondo;
	protected:
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ lbl_reporte;
	private: System::Windows::Forms::Label^ label13;
	public: System::Windows::Forms::DataGridView^ dgv_reporte;
	private:

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
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbl_reporte = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->dgv_reporte = (gcnew System::Windows::Forms::DataGridView());
			this->panel_fondo->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_reporte))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_fondo
			// 
			this->panel_fondo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_fondo->BackColor = System::Drawing::Color::LightGray;
			this->panel_fondo->Controls->Add(this->panel5);
			this->panel_fondo->Controls->Add(this->dgv_reporte);
			this->panel_fondo->Location = System::Drawing::Point(3, 3);
			this->panel_fondo->Name = L"panel_fondo";
			this->panel_fondo->Size = System::Drawing::Size(742, 501);
			this->panel_fondo->TabIndex = 12;
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->lbl_reporte);
			this->panel5->Controls->Add(this->label13);
			this->panel5->Location = System::Drawing::Point(3, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(736, 37);
			this->panel5->TabIndex = 15;
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
			// lbl_reporte
			// 
			this->lbl_reporte->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_reporte->AutoSize = true;
			this->lbl_reporte->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_reporte->Location = System::Drawing::Point(10, 9);
			this->lbl_reporte->Name = L"lbl_reporte";
			this->lbl_reporte->Size = System::Drawing::Size(131, 19);
			this->lbl_reporte->TabIndex = 0;
			this->lbl_reporte->Text = L"Reporte de facturas";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 2;
			// 
			// dgv_reporte
			// 
			this->dgv_reporte->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
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
			this->dgv_reporte->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgv_reporte->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_reporte->Location = System::Drawing::Point(17, 59);
			this->dgv_reporte->Name = L"dgv_reporte";
			this->dgv_reporte->Size = System::Drawing::Size(708, 430);
			this->dgv_reporte->TabIndex = 14;
			// 
			// Reporte_factura
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 506);
			this->Controls->Add(this->panel_fondo);
			this->Name = L"Reporte_factura";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reporte_factura";
			this->Load += gcnew System::EventHandler(this, &Reporte_factura::Reporte_factura_Load);
			this->panel_fondo->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_reporte))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	// Función que permite mostrar los datos registrados del registro de facturas y los ubica en un dgv para su correcta visualización
	void mostrarReporte(DataGridView^ dgv) {
		try {
			// Abrimos el archivo donde tenemos registrados los datos de los reportes
			ifstream file;
			file.open("factura\\Reporte de facturas.txt", ios::in);

			// Se crea una tabla con las columnas correspondientes
			System::Data::DataTable^ table = gcnew System::Data::DataTable();
			table->Clear();
			table->Columns->Add("No. Fact", String::typeid);
			table->Columns->Add("Fecha de emisión", String::typeid);
			table->Columns->Add("Cliente", String::typeid);
			table->Columns->Add("Vendedor", String::typeid);
			table->Columns->Add("Forma de pago", String::typeid);
			table->Columns->Add("Subtotal", String::typeid);
			table->Columns->Add("Total facturado", String::typeid);
			table->Columns->Add("Total pagado", String::typeid);
			table->Columns->Add("Total devuelto", String::typeid);

			// Lista bidimensional que se encargará de llenar cada celda de la tabla
			list<list<string>> datos;

			if (!file.is_open()) {
				MessageBox::Show("No se puede mostrar la tabla de registro.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else {
				// Se leen los datos del archivo línea por línea
				string line;
				while (getline(file, line)) {
					// Se crea una lista que almacenará los datos de una linea
					list<string> datos_linea;

					// Se separan los campos de la línea por el delimitador ('|')
					istringstream ss(line);
					string campo;
					while (getline(ss, campo, '|')) {
						// Se agrega el campo a la lista de datos de la línea
						datos_linea.push_back(campo);
					}

					// Se agrega la lista de datos de la línea a la lista bidimensional
					datos.push_back(datos_linea);
				}

				// Se cierra el archivo después de leer los datos
				file.close();

				// Se llena la tabla con los datos de la lista bidimensional
				for (auto it = datos.begin(); it != datos.end(); ++it) {
					// Se crea una fila para la tabla
					System::Data::DataRow^ fila = table->NewRow();

					// Se agregan los datos de la lista a la fila
					int i = 0;
					for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
						// Se agregan los campos de texto tal cual
						String^ valor = gcnew String((*it2).c_str());
						fila[i] = valor;
						i++;
					}

					// Se agrega la fila a la tabla
					table->Rows->Add(fila);
				}
				// Se asigna la tabla como fuente de datos del DataGridView
				dgv->DataSource = table;
			}
		}
		catch (const std::exception& e) {
			MessageBox::Show("Ocurrió un error al mostrar las facturas: " + gcnew System::String(e.what()));
		}
	}

	private: System::Void Reporte_factura_Load(System::Object^ sender, System::EventArgs^ e) {
		// Mostramos en un datagridview los campos del archivo de texto
		mostrarReporte(dgv_reporte);

		// Eliminamos el archivo luego de mostrar correctamente los datos, a fin de crear otro al momento de entrar a esta formulario
		remove("factura\\Reporte de facturas.txt");
	}
	};
}
