#pragma once
#include "SystemString_toStdString.h"
#include "Validaciones.h"
#include "productos/archivarProductos.h"
#include "factura/archivar_datosFactura.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Compras
	/// </summary>
	public ref class Compras : public System::Windows::Forms::Form
	{
	public:
		Compras(void)
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
		~Compras()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ tb_code;
	protected:
	private: System::Windows::Forms::Label^ lbl_codprod;
	public: System::Windows::Forms::TextBox^ tb_cant;
	private: System::Windows::Forms::Label^ lbl_cantad;
	public:
	private:
	public:

	private:

	private: System::Windows::Forms::Label^ lbldes;
	public: System::Windows::Forms::TextBox^ tb_pU;
	private: System::Windows::Forms::Label^ lbl_pU;
	public:
	private:
	public:


	private:

	private: System::Windows::Forms::TextBox^ tb_totalcompra;
	public:

	private: System::Windows::Forms::Label^ lbl_desc;
	private: System::Windows::Forms::Label^ lbl_exis;
	private: System::Windows::Forms::Label^ lblex;
	private: System::Windows::Forms::Label^ lbl_totalComp;




	private: System::Windows::Forms::Label^ lblum;

	private: System::Windows::Forms::Label^ lbl_uM;

	private: System::Windows::Forms::Button^ btn_comprar;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	private: System::Windows::Forms::Button^ btn_cancelar;
	private: System::Windows::Forms::Panel^ panel_prod;

	private: System::Windows::Forms::ErrorProvider^ errorProvider;
	private: System::Windows::Forms::PictureBox^ pB_calcular;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ lbl_vistaHora;
	private: System::Windows::Forms::Label^ lbl_vistaFecha;
	private: System::Windows::Forms::Label^ lbl_hora;
	private: System::Windows::Forms::Label^ lbl_fecha;
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
			this->tb_code = (gcnew System::Windows::Forms::TextBox());
			this->lbl_codprod = (gcnew System::Windows::Forms::Label());
			this->tb_cant = (gcnew System::Windows::Forms::TextBox());
			this->lbl_cantad = (gcnew System::Windows::Forms::Label());
			this->lbldes = (gcnew System::Windows::Forms::Label());
			this->tb_pU = (gcnew System::Windows::Forms::TextBox());
			this->lbl_pU = (gcnew System::Windows::Forms::Label());
			this->tb_totalcompra = (gcnew System::Windows::Forms::TextBox());
			this->lbl_desc = (gcnew System::Windows::Forms::Label());
			this->lbl_exis = (gcnew System::Windows::Forms::Label());
			this->lblex = (gcnew System::Windows::Forms::Label());
			this->lbl_totalComp = (gcnew System::Windows::Forms::Label());
			this->lblum = (gcnew System::Windows::Forms::Label());
			this->lbl_uM = (gcnew System::Windows::Forms::Label());
			this->btn_comprar = (gcnew System::Windows::Forms::Button());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->panel_prod = (gcnew System::Windows::Forms::Panel());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->pB_calcular = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lbl_fecha = (gcnew System::Windows::Forms::Label());
			this->lbl_hora = (gcnew System::Windows::Forms::Label());
			this->lbl_vistaFecha = (gcnew System::Windows::Forms::Label());
			this->lbl_vistaHora = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing->SuspendLayout();
			this->panel_prod->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_calcular))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb_code
			// 
			this->tb_code->Location = System::Drawing::Point(236, 25);
			this->tb_code->Name = L"tb_code";
			this->tb_code->Size = System::Drawing::Size(110, 20);
			this->tb_code->TabIndex = 12;
			this->tb_code->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Compras::tb_code_KeyDown);
			// 
			// lbl_codprod
			// 
			this->lbl_codprod->AutoSize = true;
			this->lbl_codprod->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_codprod->Location = System::Drawing::Point(89, 25);
			this->lbl_codprod->Name = L"lbl_codprod";
			this->lbl_codprod->Size = System::Drawing::Size(141, 19);
			this->lbl_codprod->TabIndex = 11;
			this->lbl_codprod->Text = L"Código del producto:";
			// 
			// tb_cant
			// 
			this->tb_cant->Location = System::Drawing::Point(236, 242);
			this->tb_cant->Name = L"tb_cant";
			this->tb_cant->Size = System::Drawing::Size(110, 20);
			this->tb_cant->TabIndex = 14;
			// 
			// lbl_cantad
			// 
			this->lbl_cantad->AutoSize = true;
			this->lbl_cantad->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_cantad->Location = System::Drawing::Point(98, 242);
			this->lbl_cantad->Name = L"lbl_cantad";
			this->lbl_cantad->Size = System::Drawing::Size(132, 19);
			this->lbl_cantad->TabIndex = 13;
			this->lbl_cantad->Text = L"Cantidad a adquirir:";
			// 
			// lbldes
			// 
			this->lbldes->AutoSize = true;
			this->lbldes->BackColor = System::Drawing::Color::White;
			this->lbldes->Location = System::Drawing::Point(54, 138);
			this->lbldes->Name = L"lbldes";
			this->lbldes->Size = System::Drawing::Size(66, 13);
			this->lbldes->TabIndex = 15;
			this->lbldes->Text = L"Descripción:";
			// 
			// tb_pU
			// 
			this->tb_pU->Location = System::Drawing::Point(236, 281);
			this->tb_pU->Name = L"tb_pU";
			this->tb_pU->Size = System::Drawing::Size(110, 20);
			this->tb_pU->TabIndex = 17;
			// 
			// lbl_pU
			// 
			this->lbl_pU->AutoSize = true;
			this->lbl_pU->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_pU->Location = System::Drawing::Point(22, 281);
			this->lbl_pU->Name = L"lbl_pU";
			this->lbl_pU->Size = System::Drawing::Size(211, 19);
			this->lbl_pU->TabIndex = 16;
			this->lbl_pU->Text = L"Precio unitario por compra: (C$)";
			// 
			// tb_totalcompra
			// 
			this->tb_totalcompra->Location = System::Drawing::Point(142, 359);
			this->tb_totalcompra->Name = L"tb_totalcompra";
			this->tb_totalcompra->ReadOnly = true;
			this->tb_totalcompra->Size = System::Drawing::Size(136, 20);
			this->tb_totalcompra->TabIndex = 18;
			this->tb_totalcompra->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lbl_desc
			// 
			this->lbl_desc->AutoSize = true;
			this->lbl_desc->BackColor = System::Drawing::Color::White;
			this->lbl_desc->Location = System::Drawing::Point(166, 13);
			this->lbl_desc->Name = L"lbl_desc";
			this->lbl_desc->Size = System::Drawing::Size(10, 13);
			this->lbl_desc->TabIndex = 19;
			this->lbl_desc->Text = L"-";
			// 
			// lbl_exis
			// 
			this->lbl_exis->AutoSize = true;
			this->lbl_exis->BackColor = System::Drawing::Color::White;
			this->lbl_exis->Location = System::Drawing::Point(166, 68);
			this->lbl_exis->Name = L"lbl_exis";
			this->lbl_exis->Size = System::Drawing::Size(10, 13);
			this->lbl_exis->TabIndex = 21;
			this->lbl_exis->Text = L"-";
			// 
			// lblex
			// 
			this->lblex->AutoSize = true;
			this->lblex->BackColor = System::Drawing::Color::White;
			this->lblex->Location = System::Drawing::Point(54, 193);
			this->lblex->Name = L"lblex";
			this->lblex->Size = System::Drawing::Size(127, 13);
			this->lblex->TabIndex = 20;
			this->lblex->Text = L"Existencias en inventario:";
			// 
			// lbl_totalComp
			// 
			this->lbl_totalComp->AutoSize = true;
			this->lbl_totalComp->BackColor = System::Drawing::SystemColors::ControlLight;
			this->lbl_totalComp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_totalComp->Location = System::Drawing::Point(131, 337);
			this->lbl_totalComp->Name = L"lbl_totalComp";
			this->lbl_totalComp->Size = System::Drawing::Size(159, 19);
			this->lbl_totalComp->TabIndex = 22;
			this->lbl_totalComp->Text = L"Total de la compra: (C$)";
			// 
			// lblum
			// 
			this->lblum->AutoSize = true;
			this->lblum->BackColor = System::Drawing::Color::White;
			this->lblum->Location = System::Drawing::Point(54, 166);
			this->lblum->Name = L"lblum";
			this->lblum->Size = System::Drawing::Size(96, 13);
			this->lblum->TabIndex = 23;
			this->lblum->Text = L"Unidad de medida:";
			// 
			// lbl_uM
			// 
			this->lbl_uM->AutoSize = true;
			this->lbl_uM->BackColor = System::Drawing::Color::White;
			this->lbl_uM->Location = System::Drawing::Point(166, 41);
			this->lbl_uM->Name = L"lbl_uM";
			this->lbl_uM->Size = System::Drawing::Size(10, 13);
			this->lbl_uM->TabIndex = 24;
			this->lbl_uM->Text = L"-";
			// 
			// btn_comprar
			// 
			this->btn_comprar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_comprar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_comprar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_comprar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_comprar->ForeColor = System::Drawing::Color::White;
			this->btn_comprar->Location = System::Drawing::Point(102, 20);
			this->btn_comprar->Name = L"btn_comprar";
			this->btn_comprar->Size = System::Drawing::Size(101, 33);
			this->btn_comprar->TabIndex = 18;
			this->btn_comprar->Text = L"Comprar";
			this->btn_comprar->UseVisualStyleBackColor = false;
			this->btn_comprar->Click += gcnew System::EventHandler(this, &Compras::btn_comprar_Click);
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_cancelar);
			this->panel_shadowing->Controls->Add(this->btn_comprar);
			this->panel_shadowing->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_shadowing->Location = System::Drawing::Point(0, 400);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(423, 74);
			this->panel_shadowing->TabIndex = 25;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_cancelar->ForeColor = System::Drawing::Color::White;
			this->btn_cancelar->Location = System::Drawing::Point(221, 20);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(101, 33);
			this->btn_cancelar->TabIndex = 19;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Compras::btn_cancelar_Click);
			// 
			// panel_prod
			// 
			this->panel_prod->BackColor = System::Drawing::Color::White;
			this->panel_prod->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_prod->Controls->Add(this->lbl_exis);
			this->panel_prod->Controls->Add(this->lbl_uM);
			this->panel_prod->Controls->Add(this->lbl_desc);
			this->panel_prod->Location = System::Drawing::Point(26, 124);
			this->panel_prod->Name = L"panel_prod";
			this->panel_prod->Size = System::Drawing::Size(366, 100);
			this->panel_prod->TabIndex = 26;
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// pB_calcular
			// 
			this->pB_calcular->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pB_calcular->Location = System::Drawing::Point(370, 279);
			this->pB_calcular->Name = L"pB_calcular";
			this->pB_calcular->Size = System::Drawing::Size(22, 26);
			this->pB_calcular->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pB_calcular->TabIndex = 27;
			this->pB_calcular->TabStop = false;
			this->pB_calcular->Click += gcnew System::EventHandler(this, &Compras::pB_calcular_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->lbl_vistaHora);
			this->panel2->Controls->Add(this->lbl_vistaFecha);
			this->panel2->Controls->Add(this->lbl_hora);
			this->panel2->Controls->Add(this->lbl_fecha);
			this->panel2->Location = System::Drawing::Point(26, 67);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(366, 48);
			this->panel2->TabIndex = 28;
			// 
			// lbl_fecha
			// 
			this->lbl_fecha->AutoSize = true;
			this->lbl_fecha->Location = System::Drawing::Point(27, 4);
			this->lbl_fecha->Name = L"lbl_fecha";
			this->lbl_fecha->Size = System::Drawing::Size(111, 13);
			this->lbl_fecha->TabIndex = 0;
			this->lbl_fecha->Text = L"Fecha de adquisición:";
			// 
			// lbl_hora
			// 
			this->lbl_hora->AutoSize = true;
			this->lbl_hora->Location = System::Drawing::Point(27, 27);
			this->lbl_hora->Name = L"lbl_hora";
			this->lbl_hora->Size = System::Drawing::Size(104, 13);
			this->lbl_hora->TabIndex = 1;
			this->lbl_hora->Text = L"Hora de adquisición:";
			// 
			// lbl_vistaFecha
			// 
			this->lbl_vistaFecha->AutoSize = true;
			this->lbl_vistaFecha->Location = System::Drawing::Point(166, 4);
			this->lbl_vistaFecha->Name = L"lbl_vistaFecha";
			this->lbl_vistaFecha->Size = System::Drawing::Size(10, 13);
			this->lbl_vistaFecha->TabIndex = 2;
			this->lbl_vistaFecha->Text = L"-";
			// 
			// lbl_vistaHora
			// 
			this->lbl_vistaHora->AutoSize = true;
			this->lbl_vistaHora->Location = System::Drawing::Point(166, 27);
			this->lbl_vistaHora->Name = L"lbl_vistaHora";
			this->lbl_vistaHora->Size = System::Drawing::Size(10, 13);
			this->lbl_vistaHora->TabIndex = 3;
			this->lbl_vistaHora->Text = L"-";
			// 
			// Compras
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(423, 474);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pB_calcular);
			this->Controls->Add(this->panel_shadowing);
			this->Controls->Add(this->lblum);
			this->Controls->Add(this->lbl_totalComp);
			this->Controls->Add(this->lblex);
			this->Controls->Add(this->tb_totalcompra);
			this->Controls->Add(this->tb_pU);
			this->Controls->Add(this->lbl_pU);
			this->Controls->Add(this->lbldes);
			this->Controls->Add(this->tb_cant);
			this->Controls->Add(this->lbl_cantad);
			this->Controls->Add(this->tb_code);
			this->Controls->Add(this->lbl_codprod);
			this->Controls->Add(this->panel_prod);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Compras";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Compras";
			this->Load += gcnew System::EventHandler(this, &Compras::Compras_Load);
			this->panel_shadowing->ResumeLayout(false);
			this->panel_prod->ResumeLayout(false);
			this->panel_prod->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pB_calcular))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Compras_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se carga una imagen que simula un botón para calcular compra
		this->pB_calcular->Image = Image::FromFile("botoncalcular.png");

		// Se muestra la fecha en la que fue realizada la compra
		string date = archivoFactura::obtenerFecha();
		this->lbl_vistaFecha->Text = gcnew String(date.c_str());

		// Se muestra la hora en la que fue realizada la compra
		string hour = archivoFactura::obtenerHora();
		this->lbl_vistaHora->Text = gcnew String(hour.c_str());
	}
	// Este control identifica cuando el usuario haya dado "Enter" a un TextBox
	private: System::Void tb_code_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			int error = 0;
			// Primero validamos que el textbox no esté vacío
			validate::isTxtBox_notEmpty(tb_code, errorProvider, "Debe ingresar un código válido", error);

			// Verificamos si hubo algún error en el proceso  e interrumpimos la compra en caso de ser así
			if (error > 0) {
				return;
			}

			// Declaramos variables que permitirán mostrar una vista previa de la información del producto buscado
			string code = conversion::to_stdstring(tb_code->Text);
			string desc = "-";
			string exist = "-";
			string uM = "-";
			string pU = "-";

			// En caso que el usuario haya dado Enter, realizamos la búsqueda del código dado
			archivoProducto::buscarProductos_porCodigo(code, desc, uM, exist, pU);

			// Si la búsqueda fue exitosa, enviamos la información a los labels
			lbl_desc->Text = gcnew String(desc.c_str());
			lbl_uM->Text = gcnew String(uM.c_str());
			lbl_exis->Text = gcnew String(exist.c_str());
		}
	}
	private: System::Void pB_calcular_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		String^ not_anInt = "Está trabajando con unidades. Debe de ingresar valores enteros positivos.";
		String^ not_aFloat = "Solo se permiten valores numéricos positivos.";
		// Validamos las entradas del usuario, verificando si son correctas
		/* En caso de que la unidad de medida sea de unidad, se le restringirá al usuario...
		...la entrada de sólo valores enteros positivos */
		if (lbl_uM->Text == "u") {
			validate::isTxtBox_posInt(tb_cant, errorProvider, not_anInt, error);
		}
		else {
			validate::isTxtBox_posFloat(tb_cant, errorProvider, not_aFloat, error);
		}
		validate::isTxtBox_posFloat(tb_pU, errorProvider, not_aFloat, error);

		// Se verifica si no hubieron errores en el proceso. Si fue así se interrumpe la compra
		if (error > 0) {
			return;
		}

		// Convertimos los valores de las cajas de texto a unos que C++ estándar pueda manejar
		float cant = stof(conversion::to_stdstring(tb_cant->Text));
		float pUnit = stof(conversion::to_stdstring(tb_pU->Text));

		// Calculamos el total de la compra por la cantidad, multiplicada por el precio unitario
		float total = cant * pUnit;

		// Se le asigna un formato de moneda al total de la compra y se muestra en la caja de texto
		tb_totalcompra->Text = total.ToString("N2");
	}
	private: System::Void btn_comprar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Hacemos unas últimas validaciones en las compras antes de actualizar el inventario
		int error = 0;
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";

		validate::isTxtBox_notEmpty(tb_code, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_cant, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_pU, errorProvider, emptyTxtBox_Message, error);

		// Verificamos que no haya ningún error en el proceso, si fue así entonces interrumpimos el proceso de compra
		if (error > 0) {
			return;
		}

		// Convertimos de System::String a std::string para pasar valores a una función de C++ estándar
		string fEmit = conversion::to_stdstring(lbl_vistaFecha->Text);
		string hEmit = conversion::to_stdstring(lbl_vistaHora->Text);
		string code = conversion::to_stdstring(tb_code->Text);
		string desc = conversion::to_stdstring(lbl_desc->Text);
		float purchasedStocks = stof(conversion::to_stdstring(tb_cant->Text));
		float acqPrice = stof(conversion::to_stdstring(tb_pU->Text));
		float totalPurchased = stof(conversion::to_stdstring(tb_totalcompra->Text));

		// Se llama una función que sumará las cantidades compradas al inventario
		archivoProducto::realizarCompras(fEmit, hEmit, code, purchasedStocks, acqPrice, totalPurchased);

		MessageBox::Show("Compra realizada exitosamente.", "Compra exitosa", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Luego de realizada la compra se vacían los textboxes para dar posibilidad a otra
		tb_code->Text = "";
		tb_cant->Text = "";
		tb_pU->Text = "";
		tb_totalcompra->Text = "";

		archivoProducto::verificar_precioCompras(code, desc, acqPrice);

	}
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
