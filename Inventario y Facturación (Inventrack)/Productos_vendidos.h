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
	/// Resumen de Productos_vendidos
	/// </summary>
	public ref class Productos_vendidos : public System::Windows::Forms::Form
	{
	public:
		Productos_vendidos(void)
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
		~Productos_vendidos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_fondo;
	public: System::Windows::Forms::DataGridView^ dgv_compProds;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ lbl_comportamientoProds;
	private: System::Windows::Forms::Label^ label13;
	// Obtenemos el tipo de unidad seleccionado a analizar
	public: String^ tipoMedida;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel_fondo = (gcnew System::Windows::Forms::Panel());
			this->dgv_compProds = (gcnew System::Windows::Forms::DataGridView());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbl_comportamientoProds = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel_fondo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_compProds))->BeginInit();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_fondo
			// 
			this->panel_fondo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_fondo->BackColor = System::Drawing::Color::LightGray;
			this->panel_fondo->Controls->Add(this->panel5);
			this->panel_fondo->Controls->Add(this->dgv_compProds);
			this->panel_fondo->Location = System::Drawing::Point(2, 2);
			this->panel_fondo->Name = L"panel_fondo";
			this->panel_fondo->Size = System::Drawing::Size(585, 405);
			this->panel_fondo->TabIndex = 11;
			// 
			// dgv_compProds
			// 
			this->dgv_compProds->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgv_compProds->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_compProds->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dgv_compProds->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_compProds->Location = System::Drawing::Point(17, 59);
			this->dgv_compProds->Name = L"dgv_compProds";
			this->dgv_compProds->Size = System::Drawing::Size(551, 334);
			this->dgv_compProds->TabIndex = 14;
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->lbl_comportamientoProds);
			this->panel5->Controls->Add(this->label13);
			this->panel5->Location = System::Drawing::Point(3, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(579, 37);
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
			// lbl_comportamientoProds
			// 
			this->lbl_comportamientoProds->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_comportamientoProds->AutoSize = true;
			this->lbl_comportamientoProds->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_comportamientoProds->Location = System::Drawing::Point(10, 9);
			this->lbl_comportamientoProds->Name = L"lbl_comportamientoProds";
			this->lbl_comportamientoProds->Size = System::Drawing::Size(215, 19);
			this->lbl_comportamientoProds->TabIndex = 0;
			this->lbl_comportamientoProds->Text = L"Análisis de la venta de productos";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 2;
			// 
			// Productos_vendidos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 410);
			this->Controls->Add(this->panel_fondo);
			this->Name = L"Productos_vendidos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Actividad comercial de los productos";
			this->Load += gcnew System::EventHandler(this, &Productos_vendidos::Productos_vendidos_Load);
			this->panel_fondo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_compProds))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		// Función que permite mostrar los datos registrados de la frecuencia de clientes y los ubica en un dgv para su correcta visualización
		void mostrar_ventaProductos(DataGridView^ dgv) {
			try {
				// Abrimos el archivo donde tenemos registrados los datos de las facturas realizadas
				ifstream file;
				file.open("factura\\Venta de productos.txt", ios::in);

				// Se crea una tabla con las columnas correspondientes
				System::Data::DataTable^ table = gcnew System::Data::DataTable();
				table->Clear();
				table->Columns->Add("Producto", String::typeid);
				table->Columns->Add("Unidad de medida", String::typeid);
				table->Columns->Add("Salidas", String::typeid);
				table->Columns->Add("Total de ganancias (C$)", String::typeid);
				table->Columns->Add("Preferencia (%)", String::typeid);

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

						// Separar los campos de la línea por el delimitador '|'
						istringstream ss(line);
						string campo;
						while (getline(ss, campo, '|')) {
							// Agregar el campo a la lista de datos de la línea
							datos_linea.push_back(campo);
						}

						// Agregar la lista de datos de la línea a la lista bidimensional
						datos.push_back(datos_linea);
					}

					// Se cierra el archivo después de leer los datos
					file.close();

					// Verificamos si la lista no obtuvo datos, si es así significa que el archivo está vacío
					if (datos.empty()) {
						MessageBox::Show("No se han registrado ventas para este tipo de unidad de medida.",
							"Sin ventas", MessageBoxButtons::OK, MessageBoxIcon::Error);
						this->Close(); // Cerramos el formulario
					}
					else {
						// Se llena la tabla con los datos de la lista bidimensional
						for (auto it = datos.begin(); it != datos.end(); ++it) {
							// Se crea una fila para la tabla
							System::Data::DataRow^ fila = table->NewRow();

							// Se agregan los datos de la lista a la fila
							int i = 0;
							for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
								// Agregar los campos de texto tal cual
								System::String^ valor = gcnew System::String((*it2).c_str());
								fila[i] = valor;
								i++;
							}

							// Se agrega la fila a la tabla
							table->Rows->Add(fila);
						}
						// Asignar la tabla como fuente de datos del DataGridView
						dgv->DataSource = table;

						// Centrar las columnas "Total invertido (C$)" y "Frecuencia de visita"
						dgv->Columns["Unidad de medida"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
						dgv->Columns["Salidas"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
						dgv->Columns["Total de ganancias (C$)"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
						dgv->Columns["Preferencia (%)"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
					}
				}
			}
			catch (const std::exception& e) {
				MessageBox::Show("Ocurrió un error al mostrar las facturas: " + gcnew System::String(e.what()));
			}
		}

	private: System::Void Productos_vendidos_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargamos los datos que determinarán el anális de ventas de los productos
		string selectedMeasure = conversion::to_stdstring(tipoMedida);
		archivoFactura::registrar_comportamientoProductos(selectedMeasure);

		// Mostramos en un datagridview los campos del archivo de texto
		mostrar_ventaProductos(dgv_compProds);

		// Eliminamos el archivo luego de mostrar correctamente los datos, a fin de crear otro al momento de entrar a esta formulario
		remove("factura\\Venta de productos.txt");
	}
	};
}
