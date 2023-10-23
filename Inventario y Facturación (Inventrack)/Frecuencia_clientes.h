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
	using namespace std;

	/// <summary>
	/// Resumen de Frecuencia_clientes
	/// </summary>
	public ref class Frecuencia_clientes : public System::Windows::Forms::Form
	{
	public:
		Frecuencia_clientes(void)
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
		~Frecuencia_clientes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel5;
	protected:
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ lbl_frecuenciaClientes;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel_fondo;
	public: System::Windows::Forms::DataGridView^ dgv_frecClientes;

	public:


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
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lbl_frecuenciaClientes = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel_fondo = (gcnew System::Windows::Forms::Panel());
			this->dgv_frecClientes = (gcnew System::Windows::Forms::DataGridView());
			this->panel5->SuspendLayout();
			this->panel_fondo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_frecClientes))->BeginInit();
			this->SuspendLayout();
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->lbl_frecuenciaClientes);
			this->panel5->Controls->Add(this->label13);
			this->panel5->Location = System::Drawing::Point(5, 5);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(579, 37);
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
			// lbl_frecuenciaClientes
			// 
			this->lbl_frecuenciaClientes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_frecuenciaClientes->AutoSize = true;
			this->lbl_frecuenciaClientes->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_frecuenciaClientes->Location = System::Drawing::Point(10, 9);
			this->lbl_frecuenciaClientes->Name = L"lbl_frecuenciaClientes";
			this->lbl_frecuenciaClientes->Size = System::Drawing::Size(168, 19);
			this->lbl_frecuenciaClientes->TabIndex = 0;
			this->lbl_frecuenciaClientes->Text = L"Frecuencia de los clientes";
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
			this->panel_fondo->BackColor = System::Drawing::Color::LightGray;
			this->panel_fondo->Controls->Add(this->dgv_frecClientes);
			this->panel_fondo->Location = System::Drawing::Point(2, 2);
			this->panel_fondo->Name = L"panel_fondo";
			this->panel_fondo->Size = System::Drawing::Size(585, 405);
			this->panel_fondo->TabIndex = 10;
			// 
			// dgv_frecClientes
			// 
			this->dgv_frecClientes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgv_frecClientes->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_frecClientes->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgv_frecClientes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_frecClientes->Location = System::Drawing::Point(17, 59);
			this->dgv_frecClientes->Name = L"dgv_frecClientes";
			this->dgv_frecClientes->Size = System::Drawing::Size(551, 334);
			this->dgv_frecClientes->TabIndex = 14;
			// 
			// Frecuencia_clientes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 410);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel_fondo);
			this->MaximizeBox = false;
			this->Name = L"Frecuencia_clientes";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Frecuencia de los clientes";
			this->Load += gcnew System::EventHandler(this, &Frecuencia_clientes::Frecuencia_clientes_Load);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel_fondo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_frecClientes))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		// Función que permite mostrar los datos registrados de la frecuencia de clientes y los ubica en un dgv para su correcta visualización
		void mostrar_FrecuenciaClientes(DataGridView^ dgv) {
			try {
				// Abrimos el archivo donde tenemos registrados los datos de las facturas realizadas
				ifstream file;
				file.open("factura\\Frecuencia de clientes.txt", ios::in);

				// Se crea una tabla con las columnas correspondientes
				System::Data::DataTable^ table = gcnew System::Data::DataTable();
				table->Clear();
				table->Columns->Add("Cliente", String::typeid);
				table->Columns->Add("Total invertido (C$)", String::typeid);
				table->Columns->Add("Frecuencia de visita (%)", String::typeid);

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
					dgv->Columns["Total invertido (C$)"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
					dgv->Columns["Frecuencia de visita (%)"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
				}
			}
			catch (const std::exception& e) {
				MessageBox::Show("Ocurrió un error al mostrar las facturas: " + gcnew System::String(e.what()));
			}
		}
	
	private: System::Void Frecuencia_clientes_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargamos los datos que determinarán la frecuencia de visita que tienen los clientes
		archivoFactura::registrar_frecuenciaClientes();

		// Mostramos en un datagridview los campos del archivo de texto
		mostrar_FrecuenciaClientes(dgv_frecClientes);

		// Eliminamos el archivo luego de mostrar correctamente los datos, a fin de crear otro al momento de entrar a esta formulario
		if (remove("factura\\Frecuencia de clientes.txt") != 0) {
			// En caso de que el proceso de anulación no haya sido correcto, enviamos un mensaje de error
			MessageBox::Show("Error al eliminar el archivo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	};
}
