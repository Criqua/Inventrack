#pragma once
#include "SystemString_toStdString.h"
#include "productos/archivarProductos.h"
#include "unidad de medida/uMedidas_archivadas.h"
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
	/// Resumen de Modificar_producto
	/// </summary>
	public ref class Modificar_producto : public System::Windows::Forms::Form
	{

	public:
		Modificar_producto(void)
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
		~Modificar_producto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_modificar;
	protected:
	private: System::Windows::Forms::Button^ btn_cancelar;
	private: System::Windows::Forms::Label^ lbl_desc;
	private: System::Windows::Forms::Panel^ panel_shadowing;
	public: System::Windows::Forms::TextBox^ tb_desc;
	private: System::Windows::Forms::Label^ lbl_umedida;
	public: System::Windows::Forms::ComboBox^ cb_umedida;
	public: System::Windows::Forms::TextBox^ tb_exist;
	private: System::Windows::Forms::Label^ lbl_exist;
	public: System::Windows::Forms::TextBox^ tb_min;
	private: System::Windows::Forms::Label^ lbl_min;
	public: System::Windows::Forms::TextBox^ tb_punit;
	private: System::Windows::Forms::Label^ lbl_punit;
	public: System::Windows::Forms::TextBox^ tb_ubic;
	private: System::Windows::Forms::Label^ lbl_ubic;
	public: System::Windows::Forms::TextBox^ tb_fexp;
	private: System::Windows::Forms::Label^ lbl_fexp;
	public: String^ code = "";
	public: String^ group = "";
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
			this->btn_modificar = (gcnew System::Windows::Forms::Button());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->lbl_desc = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->tb_desc = (gcnew System::Windows::Forms::TextBox());
			this->lbl_umedida = (gcnew System::Windows::Forms::Label());
			this->cb_umedida = (gcnew System::Windows::Forms::ComboBox());
			this->tb_exist = (gcnew System::Windows::Forms::TextBox());
			this->lbl_exist = (gcnew System::Windows::Forms::Label());
			this->tb_min = (gcnew System::Windows::Forms::TextBox());
			this->lbl_min = (gcnew System::Windows::Forms::Label());
			this->tb_punit = (gcnew System::Windows::Forms::TextBox());
			this->lbl_punit = (gcnew System::Windows::Forms::Label());
			this->tb_ubic = (gcnew System::Windows::Forms::TextBox());
			this->lbl_ubic = (gcnew System::Windows::Forms::Label());
			this->tb_fexp = (gcnew System::Windows::Forms::TextBox());
			this->lbl_fexp = (gcnew System::Windows::Forms::Label());
			this->errorProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel_shadowing->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_modificar
			// 
			this->btn_modificar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_modificar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_modificar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_modificar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_modificar->ForeColor = System::Drawing::Color::White;
			this->btn_modificar->Location = System::Drawing::Point(80, 21);
			this->btn_modificar->Name = L"btn_modificar";
			this->btn_modificar->Size = System::Drawing::Size(101, 33);
			this->btn_modificar->TabIndex = 18;
			this->btn_modificar->Text = L"Modificar";
			this->btn_modificar->UseVisualStyleBackColor = false;
			this->btn_modificar->Click += gcnew System::EventHandler(this, &Modificar_producto::btn_modificar_Click);
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_cancelar->ForeColor = System::Drawing::Color::White;
			this->btn_cancelar->Location = System::Drawing::Point(199, 21);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(101, 33);
			this->btn_cancelar->TabIndex = 19;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Modificar_producto::btn_cancelar_Click);
			// 
			// lbl_desc
			// 
			this->lbl_desc->AutoSize = true;
			this->lbl_desc->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_desc->Location = System::Drawing::Point(12, 17);
			this->lbl_desc->Name = L"lbl_desc";
			this->lbl_desc->Size = System::Drawing::Size(83, 19);
			this->lbl_desc->TabIndex = 2;
			this->lbl_desc->Text = L"Descripción";
			this->lbl_desc->Click += gcnew System::EventHandler(this, &Modificar_producto::lbl_anteriordesc_Click);
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_cancelar);
			this->panel_shadowing->Controls->Add(this->btn_modificar);
			this->panel_shadowing->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_shadowing->Location = System::Drawing::Point(0, 411);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(403, 74);
			this->panel_shadowing->TabIndex = 9;
			// 
			// tb_desc
			// 
			this->tb_desc->Location = System::Drawing::Point(16, 39);
			this->tb_desc->Name = L"tb_desc";
			this->tb_desc->Size = System::Drawing::Size(362, 20);
			this->tb_desc->TabIndex = 10;
			this->tb_desc->TextChanged += gcnew System::EventHandler(this, &Modificar_producto::textBox1_TextChanged);
			// 
			// lbl_umedida
			// 
			this->lbl_umedida->AutoSize = true;
			this->lbl_umedida->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_umedida->Location = System::Drawing::Point(12, 71);
			this->lbl_umedida->Name = L"lbl_umedida";
			this->lbl_umedida->Size = System::Drawing::Size(123, 19);
			this->lbl_umedida->TabIndex = 11;
			this->lbl_umedida->Text = L"Unidad de medida";
			// 
			// cb_umedida
			// 
			this->cb_umedida->FormattingEnabled = true;
			this->cb_umedida->Location = System::Drawing::Point(16, 94);
			this->cb_umedida->Name = L"cb_umedida";
			this->cb_umedida->Size = System::Drawing::Size(362, 21);
			this->cb_umedida->TabIndex = 12;
			this->cb_umedida->SelectedIndexChanged += gcnew System::EventHandler(this, &Modificar_producto::cb_umedida_SelectedIndexChanged);
			// 
			// tb_exist
			// 
			this->tb_exist->Location = System::Drawing::Point(16, 146);
			this->tb_exist->Name = L"tb_exist";
			this->tb_exist->Size = System::Drawing::Size(362, 20);
			this->tb_exist->TabIndex = 14;
			// 
			// lbl_exist
			// 
			this->lbl_exist->AutoSize = true;
			this->lbl_exist->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_exist->Location = System::Drawing::Point(12, 124);
			this->lbl_exist->Name = L"lbl_exist";
			this->lbl_exist->Size = System::Drawing::Size(147, 19);
			this->lbl_exist->TabIndex = 13;
			this->lbl_exist->Text = L"Existencias / Cantidad";
			// 
			// tb_min
			// 
			this->tb_min->Location = System::Drawing::Point(16, 202);
			this->tb_min->Name = L"tb_min";
			this->tb_min->Size = System::Drawing::Size(362, 20);
			this->tb_min->TabIndex = 16;
			// 
			// lbl_min
			// 
			this->lbl_min->AutoSize = true;
			this->lbl_min->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_min->Location = System::Drawing::Point(12, 180);
			this->lbl_min->Name = L"lbl_min";
			this->lbl_min->Size = System::Drawing::Size(138, 19);
			this->lbl_min->TabIndex = 15;
			this->lbl_min->Text = L"Exist. / Cant. mínima";
			// 
			// tb_punit
			// 
			this->tb_punit->Location = System::Drawing::Point(16, 257);
			this->tb_punit->Name = L"tb_punit";
			this->tb_punit->Size = System::Drawing::Size(362, 20);
			this->tb_punit->TabIndex = 18;
			// 
			// lbl_punit
			// 
			this->lbl_punit->AutoSize = true;
			this->lbl_punit->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_punit->Location = System::Drawing::Point(12, 235);
			this->lbl_punit->Name = L"lbl_punit";
			this->lbl_punit->Size = System::Drawing::Size(132, 19);
			this->lbl_punit->TabIndex = 17;
			this->lbl_punit->Text = L"Precio unitario (C$)";
			// 
			// tb_ubic
			// 
			this->tb_ubic->Location = System::Drawing::Point(16, 308);
			this->tb_ubic->Name = L"tb_ubic";
			this->tb_ubic->Size = System::Drawing::Size(362, 20);
			this->tb_ubic->TabIndex = 20;
			// 
			// lbl_ubic
			// 
			this->lbl_ubic->AutoSize = true;
			this->lbl_ubic->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_ubic->Location = System::Drawing::Point(12, 286);
			this->lbl_ubic->Name = L"lbl_ubic";
			this->lbl_ubic->Size = System::Drawing::Size(72, 19);
			this->lbl_ubic->TabIndex = 19;
			this->lbl_ubic->Text = L"Ubicación";
			// 
			// tb_fexp
			// 
			this->tb_fexp->Location = System::Drawing::Point(16, 364);
			this->tb_fexp->Name = L"tb_fexp";
			this->tb_fexp->Size = System::Drawing::Size(362, 20);
			this->tb_fexp->TabIndex = 22;
			// 
			// lbl_fexp
			// 
			this->lbl_fexp->AutoSize = true;
			this->lbl_fexp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_fexp->Location = System::Drawing::Point(12, 342);
			this->lbl_fexp->Name = L"lbl_fexp";
			this->lbl_fexp->Size = System::Drawing::Size(132, 19);
			this->lbl_fexp->TabIndex = 21;
			this->lbl_fexp->Text = L"Fecha de expiración";
			// 
			// errorProvider
			// 
			this->errorProvider->ContainerControl = this;
			// 
			// Modificar_producto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(403, 485);
			this->Controls->Add(this->tb_fexp);
			this->Controls->Add(this->lbl_fexp);
			this->Controls->Add(this->tb_ubic);
			this->Controls->Add(this->lbl_ubic);
			this->Controls->Add(this->tb_punit);
			this->Controls->Add(this->lbl_punit);
			this->Controls->Add(this->tb_min);
			this->Controls->Add(this->lbl_min);
			this->Controls->Add(this->tb_exist);
			this->Controls->Add(this->lbl_exist);
			this->Controls->Add(this->cb_umedida);
			this->Controls->Add(this->lbl_umedida);
			this->Controls->Add(this->tb_desc);
			this->Controls->Add(this->panel_shadowing);
			this->Controls->Add(this->lbl_desc);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Modificar_producto";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modificar producto";
			this->Load += gcnew System::EventHandler(this, &Modificar_producto::Modificar_producto_Load);
			this->panel_shadowing->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label_registerprovider_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Modificar_producto_Load(System::Object^ sender, System::EventArgs^ e) {
		// Se muestran las unidades de medida en un comboBox para su posible modificación
		string unitpath = "unidad de medida\\Unidades de medida registradas.txt";
		
		uMeasure::mostrarMedidas_ComboBox(unitpath, cb_umedida);
	}
	private: System::Void lbl_anteriordesc_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btn_modificar_Click(System::Object^ sender, System::EventArgs^ e) {
		int error = 0;
		String^ emptyTxtBox_Message = "Este campo es obligatorio.";
		String^ desc_isSame = "La descripción de producto que desea añadir ya está registrada.";
		String^ emptyCbBox_Message = "Seleccione una opción válida.";
		String^ not_anInt = "Está trabajando con unidades. Debe de ingresar valores enteros positivos.";
		String^ not_aFloat = "Solo se permiten valores numéricos positivos.";
		String^ emptyTxtBox_Message2 = "Este campo es obligatorio, pero puede no rellenarlo ingresando cualquier caracter <<->>.";
		String^ emin_isGreaterthan_exist = "La cantidad de existencias mínimas no pueden sobrepasar a la cantidad actual de existencias a registrar.";
		// Se realizan validaciones antes del registro de los datos del producto:

		// 1. Verificamos si los textBoxes no están vacíos:
		validate::isTxtBox_notEmpty(tb_desc, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_exist, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_min, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_punit, errorProvider, emptyTxtBox_Message, error);
		validate::isTxtBox_notEmpty(tb_ubic, errorProvider, emptyTxtBox_Message2, error);
		validate::isTxtBox_notEmpty(tb_fexp, errorProvider, emptyTxtBox_Message2, error);
		validate::isComboBox_notEmpty(cb_umedida, errorProvider, emptyCbBox_Message, error);
		validate::isDate_correct(tb_fexp, errorProvider, true, error);

		// 2. Verificamos si algunos textBoxes son enteros o flotantes positivos
		if (error == 0) {
			if (cb_umedida->Text == "u") {
				validate::isTxtBox_posInt(tb_exist, errorProvider, not_anInt, error);
				validate::isTxtBox_posInt(tb_min, errorProvider, not_anInt, error);
			}
			else {
				validate::isTxtBox_posFloat(tb_exist, errorProvider, not_aFloat, error);
				validate::isTxtBox_posFloat(tb_min, errorProvider, not_aFloat, error);
			}
			// 3. Verificamos si las existencias mínimas son menores que las existencias a ingresar
			validate::isTxtBox_greaterThan(tb_exist, tb_min, errorProvider, emin_isGreaterthan_exist, error);
		}

		// Si en alguna de las validaciones hubo errores en la entrada de datos, interrumpimos el proceso de modificación
		if (error > 0) {
			return;
		}

		// El usuario rellenó los datos de forma exitosa, procedemos al proceso de modificación de los datos
		string strcode = conversion::to_stdstring(code);
		string strgroup = conversion::to_stdstring(group);
		string newDesc = conversion::to_stdstring(this->tb_desc->Text);
		string new_uMeasure = conversion::to_stdstring(this->cb_umedida->Text);
		string newExist = conversion::to_stdstring(this->tb_exist->Text);
		string new_minExist = conversion::to_stdstring(this->tb_min->Text);
		string newUbic = conversion::to_stdstring(this->tb_ubic->Text);
		string new_pUnit = conversion::to_stdstring(this->tb_punit->Text);
		string new_fExp = conversion::to_stdstring(this->tb_fexp->Text);

		archivoProducto::modificarProducto(strcode, strgroup, newDesc, new_uMeasure, newExist, new_minExist, newUbic, new_pUnit, new_fExp);
	}
	private: System::Void cb_umedida_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}