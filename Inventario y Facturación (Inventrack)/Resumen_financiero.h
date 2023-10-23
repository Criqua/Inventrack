#pragma once
#include "SystemString_toStdString.h"
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
	/// Resumen de Resumen_financiero
	/// </summary>
	public ref class Resumen_financiero : public System::Windows::Forms::Form
	{
	public:
		Resumen_financiero(void)
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
		~Resumen_financiero()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_shadowing;
	protected:
	private: System::Windows::Forms::Button^ btn_salir;
	private: System::Windows::Forms::Panel^ panel_encab;
	private: System::Windows::Forms::Label^ lbl_encabez;


	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ lbl_valorInv;

	private: System::Windows::Forms::TextBox^ tb_valorInv;
	private: System::Windows::Forms::TextBox^ tb_totalInver;


	private: System::Windows::Forms::Label^ lbl_totalInver;
	private: System::Windows::Forms::TextBox^ tb_totalVtas;


	private: System::Windows::Forms::Label^ lbl_totalVtas;



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
			this->panel_shadowing = (gcnew System::Windows::Forms::Panel());
			this->btn_salir = (gcnew System::Windows::Forms::Button());
			this->panel_encab = (gcnew System::Windows::Forms::Panel());
			this->lbl_encabez = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->lbl_valorInv = (gcnew System::Windows::Forms::Label());
			this->tb_valorInv = (gcnew System::Windows::Forms::TextBox());
			this->tb_totalInver = (gcnew System::Windows::Forms::TextBox());
			this->lbl_totalInver = (gcnew System::Windows::Forms::Label());
			this->tb_totalVtas = (gcnew System::Windows::Forms::TextBox());
			this->lbl_totalVtas = (gcnew System::Windows::Forms::Label());
			this->panel_shadowing->SuspendLayout();
			this->panel_encab->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_shadowing
			// 
			this->panel_shadowing->BackColor = System::Drawing::Color::LightGray;
			this->panel_shadowing->Controls->Add(this->btn_salir);
			this->panel_shadowing->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_shadowing->Location = System::Drawing::Point(0, 151);
			this->panel_shadowing->Name = L"panel_shadowing";
			this->panel_shadowing->Size = System::Drawing::Size(820, 58);
			this->panel_shadowing->TabIndex = 30;
			// 
			// btn_salir
			// 
			this->btn_salir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btn_salir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_salir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_salir->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold));
			this->btn_salir->ForeColor = System::Drawing::Color::White;
			this->btn_salir->Location = System::Drawing::Point(333, 13);
			this->btn_salir->Name = L"btn_salir";
			this->btn_salir->Size = System::Drawing::Size(145, 33);
			this->btn_salir->TabIndex = 19;
			this->btn_salir->Text = L"Salir";
			this->btn_salir->UseVisualStyleBackColor = false;
			this->btn_salir->Click += gcnew System::EventHandler(this, &Resumen_financiero::btn_salir_Click);
			// 
			// panel_encab
			// 
			this->panel_encab->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_encab->BackColor = System::Drawing::Color::LightSteelBlue;
			this->panel_encab->Controls->Add(this->lbl_encabez);
			this->panel_encab->Controls->Add(this->label11);
			this->panel_encab->Controls->Add(this->label13);
			this->panel_encab->Location = System::Drawing::Point(201, 1);
			this->panel_encab->Name = L"panel_encab";
			this->panel_encab->Size = System::Drawing::Size(413, 32);
			this->panel_encab->TabIndex = 31;
			// 
			// lbl_encabez
			// 
			this->lbl_encabez->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_encabez->AutoSize = true;
			this->lbl_encabez->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_encabez->ForeColor = System::Drawing::SystemColors::InfoText;
			this->lbl_encabez->Location = System::Drawing::Point(139, 8);
			this->lbl_encabez->Name = L"lbl_encabez";
			this->lbl_encabez->Size = System::Drawing::Size(143, 17);
			this->lbl_encabez->TabIndex = 0;
			this->lbl_encabez->Text = L"Ingresos e inversiones";
			this->lbl_encabez->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 18);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 2;
			// 
			// lbl_valorInv
			// 
			this->lbl_valorInv->AutoSize = true;
			this->lbl_valorInv->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_valorInv->Location = System::Drawing::Point(24, 59);
			this->lbl_valorInv->Name = L"lbl_valorInv";
			this->lbl_valorInv->Size = System::Drawing::Size(238, 19);
			this->lbl_valorInv->TabIndex = 32;
			this->lbl_valorInv->Text = L"Valoración actual del inventario (C$)";
			// 
			// tb_valorInv
			// 
			this->tb_valorInv->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_valorInv->Location = System::Drawing::Point(28, 81);
			this->tb_valorInv->Name = L"tb_valorInv";
			this->tb_valorInv->ReadOnly = true;
			this->tb_valorInv->Size = System::Drawing::Size(144, 22);
			this->tb_valorInv->TabIndex = 33;
			// 
			// tb_totalInver
			// 
			this->tb_totalInver->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_totalInver->Location = System::Drawing::Point(333, 81);
			this->tb_totalInver->Name = L"tb_totalInver";
			this->tb_totalInver->ReadOnly = true;
			this->tb_totalInver->Size = System::Drawing::Size(144, 22);
			this->tb_totalInver->TabIndex = 35;
			// 
			// lbl_totalInver
			// 
			this->lbl_totalInver->AutoSize = true;
			this->lbl_totalInver->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_totalInver->Location = System::Drawing::Point(329, 59);
			this->lbl_totalInver->Name = L"lbl_totalInver";
			this->lbl_totalInver->Size = System::Drawing::Size(164, 19);
			this->lbl_totalInver->TabIndex = 34;
			this->lbl_totalInver->Text = L"Total de inversiones (C$)";
			// 
			// tb_totalVtas
			// 
			this->tb_totalVtas->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_totalVtas->Location = System::Drawing::Point(585, 81);
			this->tb_totalVtas->Name = L"tb_totalVtas";
			this->tb_totalVtas->ReadOnly = true;
			this->tb_totalVtas->Size = System::Drawing::Size(144, 22);
			this->tb_totalVtas->TabIndex = 37;
			// 
			// lbl_totalVtas
			// 
			this->lbl_totalVtas->AutoSize = true;
			this->lbl_totalVtas->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_totalVtas->Location = System::Drawing::Point(581, 59);
			this->lbl_totalVtas->Name = L"lbl_totalVtas";
			this->lbl_totalVtas->Size = System::Drawing::Size(224, 19);
			this->lbl_totalVtas->TabIndex = 36;
			this->lbl_totalVtas->Text = L"Total en ventas (IVA incluido [C$])";
			// 
			// Resumen_financiero
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(820, 209);
			this->Controls->Add(this->tb_totalVtas);
			this->Controls->Add(this->lbl_totalVtas);
			this->Controls->Add(this->tb_totalInver);
			this->Controls->Add(this->lbl_totalInver);
			this->Controls->Add(this->tb_valorInv);
			this->Controls->Add(this->lbl_valorInv);
			this->Controls->Add(this->panel_encab);
			this->Controls->Add(this->panel_shadowing);
			this->MaximizeBox = false;
			this->Name = L"Resumen_financiero";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Resumen financiero";
			this->Load += gcnew System::EventHandler(this, &Resumen_financiero::Resumen_financiero_Load);
			this->panel_shadowing->ResumeLayout(false);
			this->panel_encab->ResumeLayout(false);
			this->panel_encab->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Resumen_financiero_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargamos los valores monetarios de cada uno de los campos especificados

		// Valor del inventario:
		double valorInv = archivoProducto::obtener_valorInventario();
		this->tb_valorInv->Text = valorInv.ToString("N2");

		// Total inversiones:
		double totalInvertido = archivoProducto::obtener_valorInvertido();
		this->tb_totalInver->Text = totalInvertido.ToString("N2");

		// Total de ventas (IVA incluído):
		double totalVentas = archivoFactura::obtener_valorVentas();
		this->tb_totalVtas->Text = totalVentas.ToString("N2");
	}
	private: System::Void btn_salir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
