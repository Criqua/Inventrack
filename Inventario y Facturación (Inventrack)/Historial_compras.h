#pragma once
#include "SystemString_toStdString.h"
#include "productos/archivarProductos.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historial_compras
	/// </summary>
	public ref class Historial_compras : public System::Windows::Forms::Form
	{
	public:
		Historial_compras(void)
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
		~Historial_compras()
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
	private: System::Windows::Forms::Label^ lbl_comportamientoProds;
	private: System::Windows::Forms::Label^ label13;
	public: System::Windows::Forms::DataGridView^ dgv_compProds;
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
			this->lbl_comportamientoProds = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->dgv_compProds = (gcnew System::Windows::Forms::DataGridView());
			this->panel_fondo->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_compProds))->BeginInit();
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
			this->panel_fondo->Location = System::Drawing::Point(3, 3);
			this->panel_fondo->Name = L"panel_fondo";
			this->panel_fondo->Size = System::Drawing::Size(633, 433);
			this->panel_fondo->TabIndex = 12;
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
			this->panel5->Size = System::Drawing::Size(627, 37);
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
			this->lbl_comportamientoProds->Size = System::Drawing::Size(159, 19);
			this->lbl_comportamientoProds->TabIndex = 0;
			this->lbl_comportamientoProds->Text = L"Historial de las compras";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 2;
			// 
			// dgv_compProds
			// 
			this->dgv_compProds->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
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
			this->dgv_compProds->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgv_compProds->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_compProds->Location = System::Drawing::Point(17, 59);
			this->dgv_compProds->Name = L"dgv_compProds";
			this->dgv_compProds->Size = System::Drawing::Size(595, 362);
			this->dgv_compProds->TabIndex = 14;
			// 
			// Historial_compras
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(638, 440);
			this->Controls->Add(this->panel_fondo);
			this->Name = L"Historial_compras";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Historial de compras";
			this->Load += gcnew System::EventHandler(this, &Historial_compras::Historial_compras_Load);
			this->panel_fondo->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_compProds))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// Función que permite mostrar los datos registrados de la compra de mercancías y los ubica en un dgv para su correcta visualización
		void mostrar_compraProductos(DataGridView^ dgv) {
			try {
				// Abrimos el archivo donde tenemos registradas las compras efectuadas
				ifstream file;
				file.open("productos\\Historial de compras.txt", ios::in);

				// Se crea una tabla con las columnas correspondientes
				System::Data::DataTable^ table = gcnew System::Data::DataTable();
				table->Clear();
				table->Columns->Add("Fecha de emisión", String::typeid);
				table->Columns->Add("Hora de emisión", String::typeid);
				table->Columns->Add("Código", String::typeid);
				table->Columns->Add("Descripción", String::typeid);
				table->Columns->Add("Cantidad adquirida", String::typeid);
				table->Columns->Add("Unidad de medida", String::typeid);
				table->Columns->Add("Precio unit. de compra (C$)", String::typeid);
				table->Columns->Add("Total saldo comprado (C$)", String::typeid);

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
							/* Estos campos son de precio unitario y total comprado respectivamente;...
							...por tanto, se le dará un formato de moneda*/
							if (i == 6 || i == 7) {
								String^ valor = gcnew String((*it2).c_str());
								double numero = Double::Parse(valor);

								String^ valFormateado = String::Format("{0:N2}", numero);
								fila[i] = valFormateado;
							}
							else {
								// Agregar los campos de texto tal cual
								String^ valor = gcnew String((*it2).c_str());
								fila[i] = valor;
							}
							i++; // Avanzamos de campo
						}

						// Se agrega la fila a la tabla
						table->Rows->Add(fila);
					}
					// Asignar la tabla como fuente de datos del DataGridView
					dgv->DataSource = table;

					// Centramos algunas columnas especificadas
					dgv->Columns["Unidad de medida"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
					dgv->Columns["Cantidad adquirida"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
					dgv->Columns["Precio unit. de compra (C$)"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
					dgv->Columns["Total saldo comprado (C$)"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
				}
			}
			catch (const std::exception& e) {
				MessageBox::Show("Ocurrió un error al mostrar las compras: " + gcnew System::String(e.what()));
			}
		}

	private: System::Void Historial_compras_Load(System::Object^ sender, System::EventArgs^ e) {
		// Mostramos en un datagridview los campos del archivo de texto
		mostrar_compraProductos(dgv_compProds);
	}
	};
}
